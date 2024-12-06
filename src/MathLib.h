
#ifndef MATHLIB_H
#define MATHLIB_H

#define MAX_ROW 10
#define MAX_COL 10

typedef struct {
    int row;
    int column;
    int data[MAX_ROW][MAX_COL];
}Matrix;

void initializeMatrix(Matrix *m, int row, int column);
void printMatrix(const Matrix *m);
void multiplyMatrix(const Matrix *m1, const Matrix *m2, Matrix *result);

#endif // MATHLIB_H
