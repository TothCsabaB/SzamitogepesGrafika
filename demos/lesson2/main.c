#include "matrix.h"
#include <stdio.h>

int main() {
    float my_point[3] = {10.0f, 3.0f, 1.0f};
    float T[3][3];

    printf("Kiindulasi pont: X: %.2f, Y: %.2f\n", my_point[0], my_point[1]);

    scale(T, 2.0f, 2.0f);
    transform_point(my_point, T);
    printf("Skalazas (x2) utan: X: %.2f, Y: %.2f\n", my_point[0], my_point[1]);

    rotate(T, 90.0f);
    transform_point(my_point, T);
    printf("90 fokos forgatas utan: X: %.2f, Y: %.2f\n", my_point[0], my_point[1]);

    shift(T, 5.0f, -10.0f);
    transform_point(my_point, T);
    printf("Eltolas (5, -10) utan: X: %.2f, Y: %.2f\n", my_point[0], my_point[1]);

    float A[3][3], B[3][3], C[3][3];
    init_identity_matrix(A);
    shift(B, 10.0f, 0.0f);

    multiply_matrix_by_matrix(A, B, C);
    printf("Egysegmatrix * Eltolasmatrix(10, 0) eredmenye:\n");
    print_matrix(C);
	
    transform_point(my_point, C);
    printf("Transzformacio C-vel: X: %.2f, Y: %.2f\n", my_point[0], my_point[1]);

    return 0;
}