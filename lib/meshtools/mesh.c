#include "mesh.h"

void mesh_alloc(mesh_t* a, int verticesLen, int facesLen) {
    a->vertex_count = verticesLen;
    a->face_count = facesLen;
    a->vertices = malloc(verticesLen * sizeof(vertex_t));
    a->faces = malloc(facesLen * sizeof(face_t));
}

void mesh_free(mesh_t* a) {
    free(a->vertices);
    free(a->faces);
}

int mesh_triangulate(mesh_t* a) {
    // TODO: only supports triangulation of quads right now. add a proper triangulation algorithm.
    int newFaceCount = 0;
    for (int i = 0; i < a->face_count; ++i) {
        if (a->faces[i].vertex_count > 4) return 1;
        if (a->faces[i].vertex_count == 4) {
            newFaceCount++;
        }
        newFaceCount++;
    }
    
    face_t* newFaces = malloc(newFaceCount * sizeof(face_t));
    for (int i = 0, k = 0; i < a->face_count; ++i, k++) {
        if (a->faces[i].vertex_count == 4) {
            newFaces[k].vertex_count = 3;
            newFaces[k].vertices[0] = a->faces[i].vertices[0];
            newFaces[k].vertices[1] = a->faces[i].vertices[1];
            newFaces[k].vertices[2] = a->faces[i].vertices[2];
            k++;
            newFaces[k].vertex_count = 3;
            newFaces[k].vertices[0] = a->faces[i].vertices[2];
            newFaces[k].vertices[1] = a->faces[i].vertices[3];
            newFaces[k].vertices[2] = a->faces[i].vertices[0];
        } else {
            newFaces[k] = a->faces[i];
        }
    }
    
    free(a->faces);
    a->face_count = newFaceCount;
    a->faces = newFaces;
    return 0;
}
