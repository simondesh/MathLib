// created by simon deshayes 

#include <stdio.h>
#include "MathLib.h"

void initializeMatrix(Matrix *m, int row, int column){
    // Check if the matrix size is too large
    if (row > MAX_ROW || column > MAX_COL){
        printf("Matrix size is too large\n");
        return;
    }
    m -> row = row;
    m -> column = column;
    for(int i = 0; i < row; i++){
        for(int j = 0; j< column; j++){
            m -> data[i][j] = 0;
        }
    }
};

void printMatrix(const Matrix *m){
    for(int i = 0; i < m -> row; i++){
        printf("|");
        for(int j = 0; j < m -> column; j++){
            printf(" %d |", m -> data[i][j]);
        }
        printf("\n");
        for (int j = 0; j < m -> column; j++){
            printf("  -");
        }
        printf("\n");
    }
};

void multiplyMatrix(const Matrix *m1, const Matrix *m2, Matrix *result){
    if (m1 -> column != m2 -> row){
        printf("Matrix size is not compatible\n");
        return;
    }
    for(int i = 0; i < m1 -> row; i++){
        for(int j = 0; j < m2 -> column; j++){
            result -> data[i][j] = 0;
            for(int k = 0; k < m1 -> column; k++){
                result -> data[i][j] += m1 -> data[i][k] * m2 -> data[k][j];
            }
        }
    }
    result -> row = m1 -> row;
    result -> column = m2 -> column;
};

