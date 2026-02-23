#include "matrix.h"
#include <stdio.h>

int main() {
    float mat[3][3];
    float result[3][3];
    float point[3] = {1.0f, 2.0f, 1.0f};

    init_identity_matrix(mat);
    
    multiply_matrices(mat, 5.0f, result);
    
    printf("Matris szorozva 5-tel:\n");
    print_matrix(result);

    printf("\nEredeti pont: [%.2f, %.2f, %.2f]\n", point[0], point[1], point[2]);
    transform_point(point, result);
    printf("Transzformalt pont: [%.2f, %.2f, %.2f]\n", point[0], point[1], point[2]);

    return 0;
}