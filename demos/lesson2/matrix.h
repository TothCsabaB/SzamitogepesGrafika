#ifndef MATRIX_H
#define MATRIX_H

void init_identity_matrix(float matrix[3][3]);

void multiply_matrices(const float a[3][3], float b, float c[3][3]);

void transform_point(float point[3], const float transform[3][3]);

void print_matrix(const float matrix[3][3]);

void scale(float point[3], float x, float y);

void shift(float point[3], float x, float y);

void rotate(float point[3], float rotateNum);

#endif