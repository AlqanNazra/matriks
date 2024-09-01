#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Deklarasi Fungsi
void inverseMatrix();
void multiplyMatrices();
void traceMatrix();
void scalarMultiply(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], int scalar, int result[MAX_SIZE][MAX_SIZE]);
void matrixAddition(int rows, int cols, int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]);
void matrixSubtraction(int rows, int cols, int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]);
void transpose(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]);
void identityMatrix(int size, int result[MAX_SIZE][MAX_SIZE]);
void inputMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE]);
void printMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE]);

int main() {
    int choice;

    do {
        printf("\n===== MENU =====\n");
        printf("1. Invers Matriks (2x2)\n");
        printf("2. Perkalian Matriks\n");
        printf("3. Trace Matriks\n");
        printf("4. Perkalian Skalar\n");
        printf("5. Penjumlahan Matriks\n");
        printf("6. Pengurangan Matriks\n");
        printf("7. Transpose Matriks\n");
        printf("8. Matriks Identitas\n");
        printf("0. Keluar\n");
        printf("Pilih opsi: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inverseMatrix();
                break;
            case 2:
                multiplyMatrices();
                break;
            case 3:
                traceMatrix();
                break;
            case 4: {
                int rows, cols, scalar;
                int matrix[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

                printf("\nMasukkan Jumlah Baris Matriks: ");
                scanf("%d", &rows);
                printf("Masukkan Jumlah Kolom Matriks: ");
                scanf("%d", &cols);

                printf("\nMasukkan elemen matriks:\n");
                inputMatrix(rows, cols, matrix);

                printf("Masukkan skalar: ");
                scanf("%d", &scalar);

                scalarMultiply(rows, cols, matrix, scalar, result);

                printf("\nHasil Perkalian Skalar:\n");
                printMatrix(rows, cols, result);
                break;
            }
            case 5: {
                int rows, cols;
                int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

                printf("\nMasukkan Jumlah Baris Matriks: ");
                scanf("%d", &rows);
                printf("Masukkan Jumlah Kolom Matriks: ");
                scanf("%d", &cols);

                printf("\nMasukkan elemen matriks pertama:\n");
                inputMatrix(rows, cols, matrix1);

                printf("\nMasukkan elemen matriks kedua:\n");
                inputMatrix(rows, cols, matrix2);

                matrixAddition(rows, cols, matrix1, matrix2, result);

                printf("\nHasil Penjumlahan Matriks:\n");
                printMatrix(rows, cols, result);
                break;
            }
            case 6: {
                int rows, cols;
                int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

                printf("\nMasukkan Jumlah Baris Matriks: ");
                scanf("%d", &rows);
                printf("Masukkan Jumlah Kolom Matriks: ");
                scanf("%d", &cols);

                printf("\nMasukkan elemen matriks pertama:\n");
                inputMatrix(rows, cols, matrix1);

                printf("\nMasukkan elemen matriks kedua:\n");
                inputMatrix(rows, cols, matrix2);

                matrixSubtraction(rows, cols, matrix1, matrix2, result);

                printf("\nHasil Pengurangan Matriks:\n");
                printMatrix(rows, cols, result);
                break;
            }
            case 7: {
                int rows, cols;
                int matrix[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

                printf("\nMasukkan Jumlah Baris Matriks: ");
                scanf("%d", &rows);
                printf("Masukkan Jumlah Kolom Matriks: ");
                scanf("%d", &cols);

                printf("\nMasukkan elemen matriks:\n");
                inputMatrix(rows, cols, matrix);

                transpose(rows, cols, matrix, result);

                printf("\nHasil Transpose Matriks:\n");
                printMatrix(cols, rows, result); // baris dan kolom tertukar
                break;
            }
            case 8: {
                int size;
                int result[MAX_SIZE][MAX_SIZE];

                printf("\nMasukkan ukuran matriks identitas (n untuk matriks nxn): ");
                scanf("%d", &size);

                identityMatrix(size, result);

                printf("\nMatriks Identitas:\n");
                printMatrix(size, size, result);
                break;
            }
            case 0:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (choice != 0);

    return 0;
}

// Fungsi untuk memasukkan elemen matriks
void inputMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Elemen [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Fungsi untuk mencetak matriks
void printMatrix(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Fungsi untuk menghitung invers matriks 2x2
void inverseMatrix() {
    int matrix[2][2];
    float determinant;
    float inverse[2][2];

    printf("\nMasukkan elemen matriks 2x2:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("Elemen [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Menghitung determinan
    determinant = (float)(matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);

    if (determinant == 0) {
        printf("\nMatriks tidak memiliki invers karena determinan bernilai 0.\n");
        return;
    }

    // Menghitung invers
    inverse[0][0] = matrix[1][1] / determinant;
    inverse[0][1] = -matrix[0][1] / determinant;
    inverse[1][0] = -matrix[1][0] / determinant;
    inverse[1][1] = matrix[0][0] / determinant;

    printf("\nInvers Matriks:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%.2f\t", inverse[i][j]);
        }
        printf("\n");
    }
}

// Fungsi untuk perkalian dua matriks
void multiplyMatrices() {
    int rows1, cols1, rows2, cols2;
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

    printf("\nMasukkan Jumlah Baris Matriks Pertama: ");
    scanf("%d", &rows1);
    printf("Masukkan Jumlah Kolom Matriks Pertama: ");
    scanf("%d", &cols1);

    printf("\nMasukkan elemen matriks pertama:\n");
    inputMatrix(rows1, cols1, matrix1);

    printf("\nMasukkan Jumlah Baris Matriks Kedua: ");
    scanf("%d", &rows2);
    printf("Masukkan Jumlah Kolom Matriks Kedua: ");
    scanf("%d", &cols2);

    if (cols1 != rows2) {
        printf("\nPerkalian tidak dapat dilakukan karena jumlah kolom matriks pertama tidak sama dengan jumlah baris matriks kedua.\n");
        return;
    }

    printf("\nMasukkan elemen matriks kedua:\n");
    inputMatrix(rows2, cols2, matrix2);

    // Inisialisasi matriks hasil dengan nol
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
        }
    }

    // Perkalian matriks
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    printf("\nHasil Perkalian Matriks:\n");
    printMatrix(rows1, cols2, result);
}

// Fungsi untuk menghitung trace matriks
void traceMatrix() {
    int size;
    int matrix[MAX_SIZE][MAX_SIZE];
    int trace = 0;

    printf("\nMasukkan ukuran matriks persegi (n untuk matriks nxn): ");
    scanf("%d", &size);

    printf("\nMasukkan elemen matriks:\n");
    inputMatrix(size, size, matrix);

    for (int i = 0; i < size; i++) {
        trace += matrix[i][i];
    }

    printf("\nTrace Matriks = %d\n", trace);
}

// Fungsi untuk perkalian skalar dengan matriks
void scalarMultiply(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], int scalar, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix[i][j] * scalar;
        }
    }
}

// Fungsi untuk penjumlahan dua matriks
void matrixAddition(int rows, int cols, int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Fungsi untuk pengurangan dua matriks
void matrixSubtraction(int rows, int cols, int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Fungsi untuk transpose matriks
void transpose(int rows, int cols, int matrix[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// Fungsi untuk membentuk matriks identitas
void identityMatrix(int size, int result[MAX_SIZE][MAX_SIZE]) {
    // Inisialisasi semua elemen dengan nol
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = (i == j) ? 1 : 0;
        }
    }
}
