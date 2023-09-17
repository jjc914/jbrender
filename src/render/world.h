#ifndef H_WORLD
#define H_WORLD

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "linalg.h"
#include "mesh.h"

typedef struct camera {
    vector_t position;
    vector_t rotation;
    float aspect_ratio;
    float fov;
    float near, far;
    matrix_t view_matrix;
    matrix_t projection_matrix;
} camera_t;

typedef struct object {
    vector_t position;
    vector_t rotation; // TODO: use quaternions
    vector_t scale;
    matrix_t model_matrix;
    int vertices_length;
    vector_t* vertices;
    int indices_length;
    int* indices;
} object_t;

typedef struct world {
    camera_t* camera;
    int objects_length;
    object_t* objects;
} world_t;

void cam_alloc(camera_t* camera, float aspectRatio, float fov, float near, float far);
void cam_free(camera_t* camera);

void obj_alloc(object_t* object, vector_t* vertices, int verticesLen, int* indices, int indicesLen);
void obj_cpy_mesh(object_t* object, mesh_t* mesh);
void obj_alloc_cube(object_t* object);
void obj_free(object_t* object);
int obj_setpos(object_t* object, vector_t position);
int obj_setposval(object_t* object, float x, float y, float z);
int obj_setrot(object_t* object, vector_t rotation);
int obj_setrotval(object_t* object, float x, float y, float z);
int obj_setscale(object_t* object, vector_t scale);
int obj_setscaleval(object_t* object, float x, float y, float z);

int obj_trans(object_t* object, vector_t translation);
int obj_rot(object_t* object, vector_t rotation);

void world_alloc(world_t* world, camera_t* camera, int objectes_length, object_t* objects);
void world_free(world_t* world);

#endif
