#include "matrix.h"
#include <stdio.h>
#include <math.h>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

void init_zero_matrix(float matrix[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            matrix[i][j] = 0.0;
        }
    }
}

void init_identity_matrix(float matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = (i == j) ? 1.0f : 0.0f;
        }
    }
}

void multiply_matrices(const float a[3][3], float b, float c[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) { 
            c[i][j] = a[i][j] * b;
        }
    }
}

void multiply_matrix_by_matrix(const float a[3][3], const float b[3][3], float c[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            c[i][j] = 0.0f; 
            
            for (int k = 0; k < 3; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void transform_point(float point[3], const float transform[3][3]) {
    float temp[3] = {0, 0, 0}; 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            temp[i] += transform[i][j] * point[j];
        }
    }
    for(int i = 0; i < 3; i++){
		point[i] = temp[i];
	}
}

void print_matrix(const float matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%10.4f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrices(const float a[3][3], const float b[3][3], float c[3][3])
{
    int i;
    int j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void scale(float matrix[3][3], float sx, float sy) {
    init_identity_matrix(matrix);
    matrix[0][0] = sx;
    matrix[1][1] = sy;
}

void shift(float matrix[3][3], float dx, float dy) {
    init_identity_matrix(matrix);
    matrix[0][2] = dx;
    matrix[1][2] = dy;
}

void rotate(float matrix[3][3], float angle) {
    float rad = angle * (M_PI / 180.0f);
    init_identity_matrix(matrix);
    matrix[0][0] = cos(rad);
    matrix[0][1] = -sin(rad);
    matrix[1][0] = sin(rad);
    matrix[1][1] = cos(rad);
}