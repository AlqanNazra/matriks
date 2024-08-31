#include <stdio.h>
#include <stdlib.h>

void inputMatrix(int **matrix, int rows, int cols) {
    printf("Masukkan elemen-elemen matriks (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Elemen [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int **matrix, int rows, int cols) {
    printf("Matriks yang dimasukkan:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// int main() {
//     int rows, cols;

//     printf("Masukkan jumlah baris matriks: ");
//     scanf("%d", &rows);
//     printf("Masukkan jumlah kolom matriks: ");
//     scanf("%d", &cols);

//     int **matrix = (int **)malloc(rows * sizeof(int *));
//     for (int i = 0; i < rows; i++) {
//         matrix[i] = (int *)malloc(cols * sizeof(int));
//     }

//     inputMatrix(matrix, rows, cols);

//     printMatrix(matrix, rows, cols);

//     for (int i = 0; i < rows; i++) {
//         free(matrix[i]);
//     }
//     free(matrix);

//     return 0;
// }
