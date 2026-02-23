#include "matrix.h"
#include <stdio.h>

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

void transform_point(float point[3], const float transform[3][3]) {
    float temp[3] = {0, 0, 0}; 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            temp[i] += transform[i][j] * point[j];
        }
    }
    point[0] = temp[0];
    point[1] = temp[1];
    point[2] = temp[2];
}

void print_matrix(const float matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%10.4f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void scale(float point[3], float x, float y){
    float matrix[3][3] = {
        {x, 0, 0},
        {0, y, 0},
        {0, 0, 1}
    };
    transform_point(point, matrix);
}

void shift(float point[3], float shiftNum){
    float matrix[3][3] = {
        {x, 0, 0},
        {0, y, 0},
        {0, 0, 1}
    };
}