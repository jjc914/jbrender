#include "linalg.h"

void mat_alloc(matrix_t* a, int height, int width) {
    a->height = height;
    a->width = width;
    a->data = malloc(height * width * sizeof(float));
}

void mat_free(matrix_t* a) {
    free(a->data);
}

void mat_cpy(matrix_t* to, matrix_t* from) {
    mat_alloc(to, from->height, from->width);
    to->height = from->height;
    to->width = from->width;
    memcpy(to->data, from->data, from->height * from->width * sizeof(float));
}

int mat_set(matrix_t* a, int y, int x, float value) {
    if (y < 0 || y > a->height || x < 0 || x > a->width) return 1;
    a->data[y * a->height + x] = value;
    return 0;
}

int mat_setall(matrix_t* a, float* data, int len) {
    if (len != a->height * a->width) return 1;
    memcpy(a->data, data, len * sizeof(float));
    return 0;
}

int mat_trans4x4(matrix_t* a, vector_t trans) {
    if (trans.length != 4) return 1;
    mat_alloc(a, 4, 4);
    
    float x = trans.data[0];
    float y = trans.data[1];
    float z = trans.data[2];
    
    a->data[0] = 1;
    a->data[1] = 0;
    a->data[2] = 0;
    a->data[3] = x;
    
    a->data[4] = 0;
    a->data[5] = 1;
    a->data[6] = 0;
    a->data[7] = -y;
    
    a->data[8] = 0;
    a->data[9] = 0;
    a->data[10] = 1;
    a->data[11] = z;
    
    a->data[12] = 0;
    a->data[13] = 0;
    a->data[14] = 0;
    a->data[15] = 1;
//    mat_print(a);
    return 0;
}

int mat_rot4x4(matrix_t* a, vector_t rot) {
    if (rot.length != 4) return 1;
    mat_alloc(a, 4, 4);
    
    float x = rot.data[0];
    float y = rot.data[1];
    float z = rot.data[2];

    float sinx = sin(x);
    float cosx = cos(x);
    float siny = sin(y);
    float cosy = cos(y);
    float sinz = sin(z);
    float cosz = cos(z);
    
    a->data[0] = cosy * cosz;
    a->data[1] = sinx * siny * cosz - cosx * sinz;
    a->data[2] = cosx * siny * cosz + sinx * sinz;
    a->data[3] = 0;
    
    a->data[4] = cosy * sinz;
    a->data[5] = sinx * siny * sinz + cosx * cosz;
    a->data[6] = cosx * siny * sinz - sinx * cosz;
    a->data[7] = 0;
    
    a->data[8] = -siny;
    a->data[9] = sinx * cosy;
    a->data[10] = cosx * cosy;
    a->data[11] = 0;
    
    a->data[12] = 0;
    a->data[13] = 0;
    a->data[14] = 0;
    a->data[15] = 1;
    return 0;
}

int mat_scale4x4(matrix_t* a, vector_t scale) {
    if (scale.length != 4) return 1;
    mat_alloc(a, 4, 4);
    
    float x = scale.data[0];
    float y = scale.data[1];
    float z = scale.data[2];
    
    a->data[0] = x;
    a->data[1] = 0;
    a->data[2] = 0;
    a->data[3] = 0;
    
    a->data[4] = 0;
    a->data[5] = y;
    a->data[6] = 0;
    a->data[7] = 0;
    
    a->data[8] = 0;
    a->data[9] = 0;
    a->data[10] = z;
    a->data[11] = 0;
    
    a->data[12] = 0;
    a->data[13] = 0;
    a->data[14] = 0;
    a->data[15] = 1;
    return 0;
}

void mat_proj4x4(matrix_t* a, float aspectRatio, float fov, float near, float far) {
    float s = 1 / (tan((fov / 2) * DEG_2_RAD));
    float c = far / (far - near);
    mat_alloc(a, 4, 4);
    
    a->data[0] = aspectRatio * s;
    a->data[1] = 0;
    a->data[2] = 0;
    a->data[3] = 0;
    
    a->data[4] = 0;
    a->data[5] = s;
    a->data[6] = 0;
    a->data[7] = 0;
    
    a->data[8] = 0;
    a->data[9] = 0;
    a->data[10] = c;
    a->data[11] = -c * near;
    
    a->data[12] = 0;
    a->data[13] = 0;
    a->data[14] = 1;
    a->data[15] = 0;
}

void mat_print(matrix_t* a) {
    for (int y = 0; y < a->height; y++) {
        for (int x = 0; x < a->width; x++) {
            printf("%.2f ", a->data[y * a->width + x]);
        }
        printf("\n");
    }
}

void vec_alloc(vector_t* a, int length) {
    a->length = length;
    a->data = malloc(length * sizeof(float));
}

void vec_alloc_4(vector_t* a, float x, float y, float z, float w) {
    vec_alloc(a, 4);
    a->data[0] = x;
    a->data[1] = y;
    a->data[2] = z;
    a->data[3] = w;
}

void vec_free(vector_t* a) {
   free(a->data);
}

void vec_cpy(vector_t* to, vector_t* from) {
    vec_alloc(to, from->length);
    to->length = from->length;
    memcpy(to->data, from->data, from->length * sizeof(float));
}

int vec_set(vector_t* a, int i, float value) {
    if (i < 0 || i > a->length) return 1;
    a->data[i] = value;
    return 0;
}

int vec_setall(vector_t* a, float* data, int len) {
    if (len != a->length) return 1;
    memcpy(a->data, data, len * sizeof(float));
    return 0;
}

void vec_print(vector_t* a) {
    for (int i = 0; i < a->length; ++i) {
        printf("%.2f ", a->data[i]);
    }
    printf("\n");
}

int vv_add(vector_t* o, vector_t a, vector_t b) {
    if (a.length != b.length) return 1;
    vec_alloc(o, a.length);
    for (int i = 0; i < o->length; ++i) {
        o->data[i] = a.data[i] + b.data[i];
    }
    return 0;
}

int vv_subtract(vector_t* o, vector_t a, vector_t b) {
    if (a.length != b.length) return 1;
    vec_alloc(o, a.length);
    for (int i = 0; i < o->length; ++i) {
        o->data[i] = a.data[i] - b.data[i];
    }
    return 0;
}

int mm_multiply(matrix_t* o, matrix_t a, matrix_t b) {
    if (a.width != b.height) return 1;
    mat_alloc(o, a.height, b.width);
    int i = 0;
    for (int y = 0; y < a.height; y++) {
        for (int x = 0; x < b.width; x++) {
            float val = 0;
            for (int xy = 0; xy < a.width; xy++) {
                val += a.data[y * a.width + xy] * b.data[xy * b.width + x];
            }
            o->data[i] = val;
            ++i;
        }
    }
    return 0;
}

int vm_multiply(vector_t* o, vector_t a, matrix_t b) {
    if (a.length != b.height) return 1;
    vec_alloc(o, b.width);
    int i = 0;
    for (int x = 0; x < b.width; x++) {
        float val = 0;
        for (int xy = 0; xy < a.length; xy++) {
            val += a.data[xy] * b.data[xy * b.width + x];
        }
        o->data[i] = val;
        ++i;
    }
    return 0;
}

int mv_multiply(vector_t* o, matrix_t a, vector_t b) {
    if (a.width != b.length) return 1;
    vec_alloc(o, a.height);
    int i = 0;
    for (int y = 0; y < a.height; y++) {
        float val = 0;
        for (int xy = 0; xy < b.length; xy++) {
            val += a.data[y * a.width + xy] * b.data[xy];
        }
        o->data[i] = val;
        ++i;
    }
    return 0;
}

int vv_dot(float* o, vector_t a, vector_t b) {
    if (a.length != b.length) return 1;
    *o = 0.0;
    for (int i = 0; i < a.length; ++i) {
        *o += a.data[i] * b.data[i];
    }
    return 0;
}

int vv_cross_3(vector_t* o, vector_t a, vector_t b) {
    if (a.length != 3 || b.length != 3) return 1;
    vec_alloc(o, 3);
    o->data[0] = a.data[1] * b.data[2] - a.data[2] * b.data[1];
    o->data[1] = a.data[0] * b.data[2] - a.data[2] * b.data[0];
    o->data[2] = a.data[0] * b.data[1] - a.data[1] * b.data[0];
    return 0;
}

void mat_scale(matrix_t* a, float s) {
    for (int i = 0; i < a->width * a->height; ++i) {
        a->data[i] *= s;
    }
}

void vec_scale(vector_t* a, float s) {
    for (int i = 0; i < a->length; ++i) {
        a->data[i] *= s;
    }
}
