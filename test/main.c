
#include "MathLib.h"
#include <stdio.h>

int main(){
    Matrix matA, matB, matC;

    initializeMatrix(&matA, 2, 3);
    initializeMatrix(&matB, 3, 2);

    // Assign to matA
    int counter = 1;
    for (int i = 0; i < matA.row; ++i) {
        for (int j = 0; j < matA.column; ++j) {
            matA.data[i][j] = counter++;
        }
    }

    // Assign to matB
    counter = 1;
    for (int i = 0; i < matB.row; ++i) {
        for (int j = 0; j < matB.column; ++j) {
            matB.data[i][j] = counter++;
        }
    }

    // Print matA
    printf("Matrix A:\n");
    printMatrix(&matA);

    // Print matB
    printf("Matrix B:\n");
    printMatrix(&matB);

    // Multiply matA and matB
    multiplyMatrix(&matA, &matB, &matC);

    // Print matC
    printf("Matrix C (A * B):\n");
    printMatrix(&matC);

    return 0;
}