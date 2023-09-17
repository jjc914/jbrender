#ifndef H_MESH
#define H_MESH

#include <stdlib.h>
#include <stdio.h>

typedef struct vertex {
    double x, y, z;
} vertex_t;

typedef struct face {
    int vertex_count;
    int vertices[64];
} face_t;

typedef struct mesh {
    int vertex_count;
    vertex_t* vertices;
    int face_count;
    face_t* faces;
} mesh_t;

void mesh_alloc(mesh_t* a, int verticesLen, int facesLen);
void mesh_free(mesh_t* a);

int mesh_triangulate(mesh_t* a);

#endif
