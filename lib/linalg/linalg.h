#ifndef H_LINALG
#define H_LINALG

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#ifndef RAD_2_DEG
#define RAD_2_DEG 57.29577951
#endif

#ifndef DEG_2_RAD
#define DEG_2_RAD 0.01745329252
#endif

typedef struct matrix {
    int height, width;
    float* data;
} matrix_t;

typedef struct vector {
    int length;
    float* data;
} vector_t;

void mat_alloc(matrix_t* a, int height, int width);
void mat_free(matrix_t* a);
void mat_cpy(matrix_t* to, matrix_t* from);
int mat_set(matrix_t* a, int y, int x, float value);
int mat_setall(matrix_t* a, float* data, int len);
int mat_trans4x4(matrix_t* a, vector_t trans);
int mat_rot4x4(matrix_t* a, vector_t rot);
int mat_scale4x4(matrix_t* a, vector_t scale);
void mat_proj4x4(matrix_t* a, float aspectRatio, float fov, float near, float far);
void mat_print(matrix_t* a);

void vec_alloc(vector_t* a, int length);
void vec_alloc_4(vector_t* a, float x, float y, float z, float w);
void vec_free(vector_t* a);
void vec_cpy(vector_t* to, vector_t* from);
int vec_set(vector_t* a, int i, float value);
int vec_setall(vector_t* a, float* data, int len);
void vec_print(vector_t* a);

int vv_add(vector_t* o, vector_t a, vector_t b);
int vv_subtract(vector_t* o, vector_t a, vector_t b);

int mm_multiply(matrix_t* o, matrix_t a, matrix_t b);
int vm_multiply(vector_t* o, vector_t a, matrix_t b);
int mv_multiply(vector_t* o, matrix_t a, vector_t b);

int vv_dot(float* o, vector_t a, vector_t b);

int vv_cross_3(vector_t* o, vector_t a, vector_t b);

void mat_scale(matrix_t* a, float s);
void vec_scale(vector_t* a, float s);

#endif
