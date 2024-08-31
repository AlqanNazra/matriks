#include <stdio.h>

#define ROWS 3  
#define COLS 3  

void scalarMultiply(int matrix[ROWS][COLS], int scalar, int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = matrix[i][j] * scalar;
        }
    }
}

void printMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void inputMatrix(int matrix[ROWS][COLS]) {
    printf("Masukkan elemen-elemen matriks (%dx%d):\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("Elemen [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

int main() {
    int matrix[ROWS][COLS];
    int scalar;
    int result[ROWS][COLS];

    inputMatrix(matrix);

    printf("Masukkan nilai skalar: ");
    scanf("%d", &scalar);

    scalarMultiply(matrix, scalar, result);

    printf("Matrix setelah dikalikan dengan %d:\n", scalar);
    printMatrix(result);

    return 0;
}
