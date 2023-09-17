#include "world.h"

static void set_model_matrix(object_t* object) {
    matrix_t transMatrix, rotMatrix, scaleMatrix;
    mat_trans4x4(&transMatrix, object->position);
    mat_rot4x4(&rotMatrix, object->rotation);
    mat_scale4x4(&scaleMatrix, object->scale);
    
    matrix_t transRotMatrix;
    mm_multiply(&transRotMatrix, transMatrix, rotMatrix);
    mm_multiply(&object->model_matrix, transRotMatrix, scaleMatrix);
    
    mat_free(&transMatrix);
    mat_free(&rotMatrix);
    mat_free(&scaleMatrix);
}

static void set_view_matrix(camera_t* camera) {
    matrix_t transMatrix, rotMatrix;
    
    vector_t invPosition;
    vec_cpy(&invPosition, &camera->position);
    invPosition.data[0] *= -1;
    invPosition.data[1] *= -1;
    invPosition.data[2] *= -1;
    vector_t invRotation;
    vec_cpy(&invRotation, &camera->rotation);
    invRotation.data[0] *= -1;
    invRotation.data[1] *= -1;
    invRotation.data[2] *= -1;
    mat_trans4x4(&transMatrix, invPosition);
    mat_rot4x4(&rotMatrix, invRotation);
    
    mm_multiply(&camera->view_matrix, transMatrix, rotMatrix);
    
    vec_free(&invPosition);
    vec_free(&invRotation);
}

// https://www.scratchapixel.com/lessons/3d-basic-rendering/perspective-and-orthographic-projection-matrix/building-basic-perspective-projection-matrix
static void set_projection_matrix(camera_t* camera) {
    mat_proj4x4(&camera->projection_matrix, camera->aspect_ratio, camera->fov, camera->near, camera->far);
}

void cam_alloc(camera_t* camera, float aspectRatio, float fov, float near, float far) {
    vec_alloc_4(&camera->position, 0, 0, 0, 1);
    vec_alloc_4(&camera->rotation, 0, 0, 0, 1);
    camera->aspect_ratio = aspectRatio;
    camera->fov = fov;
    camera->near = near;
    camera->far = far;
    set_view_matrix(camera);
    set_projection_matrix(camera);
}

void cam_free(camera_t* camera) {
    vec_free(&camera->position);
    vec_free(&camera->rotation);
    mat_free(&camera->view_matrix);
    mat_free(&camera->projection_matrix);
}

void obj_alloc(object_t* object, vector_t* vertices, int verticesLen, int* indices, int indicesLen) {
    object->vertices_length = verticesLen;
    object->vertices = malloc(verticesLen * sizeof(vector_t));
    memcpy(object->vertices, vertices, verticesLen * sizeof(vector_t));
    object->indices_length = indicesLen;
    object->indices = malloc(indicesLen * sizeof(int));
    memcpy(object->indices, indices, indicesLen * sizeof(int));
    vec_alloc_4(&object->position, 0, 0, 0, 1);
    vec_alloc_4(&object->rotation, 0, 0, 0, 1);
    vec_alloc_4(&object->scale, 1, 1, 1, 1);
    mat_alloc(&object->model_matrix, 4, 4);
    set_model_matrix(object);
}

void obj_alloc_cube(object_t* object) {
    vector_t vertices[8];
    vec_alloc_4(&vertices[0], -1, -1,  1, 1);
    vec_alloc_4(&vertices[1],  1, -1,  1, 1);
    vec_alloc_4(&vertices[2], -1,  1,  1, 1);
    vec_alloc_4(&vertices[3],  1,  1,  1, 1);
    vec_alloc_4(&vertices[4], -1, -1, -1, 1);
    vec_alloc_4(&vertices[5],  1, -1, -1, 1);
    vec_alloc_4(&vertices[6], -1,  1, -1, 1);
    vec_alloc_4(&vertices[7],  1,  1, -1, 1);
    int indices[36] = {
        // top
        2, 6, 7,
        2, 3, 7,

        // bottom
        0, 5, 4,
        0, 1, 5,

        // left
        0, 6, 2,
        0, 4, 6,

        // right
        1, 7, 3,
        1, 5, 7,

        // front
        0, 3, 2,
        0, 1, 3,

        // back
        4, 7, 6,
        4, 5, 7
    };
    obj_alloc(object, vertices, 8, indices, 36);
}

void obj_cpy_mesh(object_t* object, mesh_t* mesh) {
    vector_t* vertices = malloc(mesh->vertex_count * sizeof(vector_t));
    for (int i = 0; i < mesh->vertex_count; ++i) {
        vec_alloc_4(&vertices[i], mesh->vertices[i].x, mesh->vertices[i].y, mesh->vertices[i].z, 1);
    }
    int* indices = malloc(mesh->face_count * 3 * sizeof(int));
    for (int i = 0; i < mesh->face_count * 3; i+=3) {
        indices[i] = mesh->faces[i/3].vertices[0] - 1;
        indices[i+1] = mesh->faces[i/3].vertices[1] - 1;
        indices[i+2] = mesh->faces[i/3].vertices[2] - 1;
    }
    obj_alloc(object, vertices, mesh->vertex_count, indices, mesh->face_count * 3);
    free(vertices);
    free(indices);
}

void obj_free(object_t* object) {
    free(object->vertices);
    free(object->indices);
    vec_free(&object->position);
    vec_free(&object->rotation);
    vec_free(&object->scale);
    mat_free(&object->model_matrix);
}

int obj_setpos(object_t* object, vector_t position) {
    if (position.length != 4) return 1;
    object->position = position;
    mat_free(&object->model_matrix);
    set_model_matrix(object);
    return 0;
}

int obj_setposval(object_t* object, float x, float y, float z) {
    object->position.data[0] = x;
    object->position.data[1] = y;
    object->position.data[2] = z;
    mat_free(&object->model_matrix);
    set_model_matrix(object);
    return 0;
}

int obj_setrot(object_t* object, vector_t rotation) {
    if (rotation.length != 4) return 1;
    object->rotation = rotation;
    mat_free(&object->model_matrix);
    set_model_matrix(object);
    return 0;
}

int obj_setrotval(object_t* object, float x, float y, float z) {
    object->rotation.data[0] = x;
    object->rotation.data[1] = y;
    object->rotation.data[2] = z;
    mat_free(&object->model_matrix);
    set_model_matrix(object);
    return 0;
}

int obj_setscale(object_t* object, vector_t scale) {
    if (scale.length != 4) return 1;
    object->scale = scale;
    mat_free(&object->model_matrix);
    set_model_matrix(object);
    return 0;
}

int obj_setscaleval(object_t* object, float x, float y, float z) {
    object->scale.data[0] = x;
    object->scale.data[1] = y;
    object->scale.data[2] = z;
    mat_free(&object->model_matrix);
    set_model_matrix(object);
    return 0;
}

int obj_trans(object_t* object, vector_t translation) {
    if (translation.length != 4) return 1;
    object->position.data[0] += translation.data[0];
    object->position.data[1] += translation.data[1];
    object->position.data[2] += translation.data[2];
    object->position.data[3] += translation.data[3];
    mat_free(&object->model_matrix);
    set_model_matrix(object);
    return 0;
}

int obj_rot(object_t* object, vector_t rotation) {
    if (rotation.length != 4) return 1;
    object->rotation.data[0] += rotation.data[0];
    object->rotation.data[1] += rotation.data[1];
    object->rotation.data[2] += rotation.data[2];
    object->rotation.data[3] += rotation.data[3];
    mat_free(&object->model_matrix);
    set_model_matrix(object);
    return 0;
}

void world_alloc(world_t* world, camera_t* camera, int objects_length, object_t* objects) {
    world->camera = camera;
    world->objects_length = objects_length;
    world->objects = objects;
}

void world_free(world_t* world) {
    
}
