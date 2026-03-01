#ifndef MATRIX_H
#define MATRIX_H

void init_identity_matrix(float matrix[3][3]);

void init_zero_matrix(float matrix[3][3]);

void multiply_matrices(const float a[3][3], float b, float c[3][3]);

void multiply_matrix_by_matrix(const float a[3][3], const float b[3][3], float c[3][3]);

void transform_point(float point[3], const float transform[3][3]);

void print_matrix(const float matrix[3][3]);

void add_matrices(const float a[3][3], const float b[3][3], float c[3][3]);

void scale(float matrix[3][3], float sx, float sy);

void shift(float matrix[3][3], float dx, float dy);

void rotate(float matrix[3][3], float angle);
#endif