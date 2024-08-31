#include <stdio.h>
#include <stdlib.h>

#define ROWS 100
#define COLS 100

// Function declarations
void inverseMatrix();
void multiplyMatrices();
void traceMatrix();
int** createZeroMatrix(int rows, int cols);
void scalarMultiply(int matrix[ROWS][COLS], int scalar, int result[ROWS][COLS]);
void tambah_tambah(int matrik1[100][100], int matriks2[100][100], int panjang, int lebar, int hasil[100][100]);
void tambah_kurang(int matrik1[100][100], int matriks2[100][100], int panjang, int lebar, int hasil[100][100]);
void invers(int matriks[100][100], int panjang, int lebar, int transpose[100][100]);
void identitas(int matriks[100][100], int panjang, int lebar);

int main() {
    int choice;
    int A[ROWS][COLS], B[ROWS][COLS];
    int hasil[ROWS][COLS];
    int baris1, kolom1, baris2, kolom2, scalar;

    printf("PROGRAM MATRIKS\n");
    printf("Syarat: Jumlah Kolom matriks pertama harus sama dengan jumlah baris matriks kedua\n");

    printf("MATRIKS PERTAMA\n");
    printf("\nMasukkan Jumlah Baris: ");
    scanf("%d", &baris1);
    printf("Masukkan Jumlah Kolom: ");
    scanf("%d", &kolom1);

    printf("Masukkan Nilai Matriks Pertama\n");
    for (int i = 1; i <= baris1; i++) {
        for (int j = 1; j <= kolom1; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("MATRIKS KEDUA\n");
    printf("\nMasukkan Jumlah Baris: ");
    scanf("%d", &baris2);
    printf("Masukkan Jumlah Kolom: ");
    scanf("%d", &kolom2);

    while (kolom1 != baris2) {
        printf("KOLOM MATRIKS PERTAMA TIDAK SAMA DENGAN BARIS MATRIKS KEDUA!!!\n");
        printf("\nMasukkan Jumlah Baris: ");
        scanf("%d", &baris2);
        printf("Masukkan Jumlah Kolom: ");
        scanf("%d", &kolom2);
    }

    printf("Masukkan Nilai Matriks Kedua\n");
    for (int i = 1; i <= baris2; i++) {
        for (int j = 1; j <= kolom2; j++) {
            printf("B[%d][%d] = ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    do {
        printf("\n===== MENU =====\n");
        printf("1. Invers Matriks\n");
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
            case 4:
                printf("Masukkan skalar: ");
                scanf("%d", &scalar);
                scalarMultiply(A, scalar, hasil);
                printf("Hasil Perkalian Skalar:\n");
                for (int i = 1; i <= baris1; i++) {
                    for (int j = 1; j <= kolom1; j++) {
                        printf(" %d ", hasil[i][j]);
                    }
                    printf("\n");
                }
                break;
            case 5:
                tambah_tambah(A, B, baris1, kolom1, hasil);
                printf("Hasil Penjumlahan Matriks:\n");
                for (int i = 1; i <= baris1; i++) {
                    for (int j = 1; j <= kolom1; j++) {
                        printf(" %d ", hasil[i][j]);
                    }
                    printf("\n");
                }
                break;
            case 6:
                tambah_kurang(A, B, baris1, kolom1, hasil);
                printf("Hasil Pengurangan Matriks:\n");
                for (int i = 1; i <= baris1; i++) {
                    for (int j = 1; j <= kolom1; j++) {
                        printf(" %d ", hasil[i][j]);
                    }
                    printf("\n");
                }
                break;
            case 7:
                invers(A, baris1, kolom1, hasil);
                break;
            case 8:
                identitas(A, baris1, kolom1);
                break;
            case 0:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (choice != 0);

    return 0;
}

// Function definitions

void inverseMatrix() {
    int kolom1 = 2, baris1 = 2; // Invers matriks hanya untuk 2x2
    int A[baris1 + 1][kolom1 + 1];
    int temp;
    float B[baris1 + 1][kolom1 + 1];
    float det;

    printf("Masukkan Nilai Matriks 2x2\n");
    for (int i = 1; i <= baris1; i++) {
        for (int j = 1; j <= kolom1; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    det = (A[1][1] * A[2][2]) - (A[1][2] * A[2][1]);
    if (det == 0) {
        printf("Matriks tidak memiliki invers\n");
    } else {
        temp = A[1][1];
        A[1][1] = A[2][2];
        A[2][2] = temp;

        A[1][2] = -A[1][2];
        A[2][1] = -A[2][1];
        for (int i = 1; i <= kolom1; i++) {
            for (int j = 1; j <= kolom1; j++) {
                B[i][j] = 1/det * A[i][j]; 
            }
        }
        printf("Invers Matriks:\n");
        for (int i = 1; i <= baris1; i++) {
            for (int j = 1; j <= kolom1; j++) {
                printf(" %f ", B[i][j]);
            }
            printf("\n");
        }
    }
}

void multiplyMatrices() {
    int kolom1, baris1, kolom2, baris2;

    printf("\nMasukkan Jumlah Baris Matriks Pertama: ");
    scanf("%d", &baris1);
    printf("Masukkan Jumlah Kolom Matriks Pertama: ");
    scanf("%d", &kolom1);

    int A[baris1 + 1][kolom1 + 1];
    printf("Masukkan Nilai Matriks Pertama\n");
    for (int i = 1; i <= baris1; i++) {
        for (int j = 1; j <= kolom1; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    do {
        printf("\nMasukkan Jumlah Baris Matriks Kedua: ");
        scanf("%d", &baris2);
        printf("Masukkan Jumlah Kolom Matriks Kedua: ");
        scanf("%d", &kolom2);

        if (kolom1 != baris2) {
            printf("KOLOM MATRIKS PERTAMA TIDAK SAMA DENGAN BARIS MATRIKS KEDUA!!!\n");
        }
    } while (kolom1 != baris2);

    int B[baris2 + 1][kolom2 + 1];
    printf("Masukkan Nilai Matriks Kedua\n");
    for (int i = 1; i <= baris2; i++) {
        for (int j = 1; j <= kolom2; j++) {
            printf("B[%d][%d] = ", i, j);
            scanf("%d", &B[i][j]);            
        }
    }

    int C[baris1 + 1][kolom2 + 1];
    for (int i = 1; i <= baris1; i++) {
        for (int j = 1; j <= kolom2; j++) {
            C[i][j] = 0;
            for (int k = 1; k <= baris2; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("Hasil Perkalian Matriks Pertama dan Kedua:\n");
    for (int i = 1; i <= baris1; i++) {
        for (int j = 1; j <= kolom2; j++) {
            printf(" %d ", C[i][j]);
        }
        printf("\n");
    }
}

void traceMatrix() {
    int kolom1, baris1, trace = 0;

    printf("\nMasukkan Jumlah Baris Matriks: ");
    scanf("%d", &baris1);
    printf("Masukkan Jumlah Kolom Matriks: ");
    scanf("%d", &kolom1);

    if (baris1 != kolom1) {
        printf("Matriks Bukan Persegi\nTrace Matriks Tidak Terdefinisi\n");
        return;
    }

    int A[baris1 + 1][kolom1 + 1];
    printf("Masukkan Nilai Matriks\n");
    for (int i = 1; i <= baris1; i++) {
        for (int j = 1; j <= kolom1; j++) {
            printf("A[%d][%d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    for (int i = 1; i <= baris1; i++) {
        trace += A[i][i];
    }

    printf("Trace Matriks = %d\n", trace);
}

int** createZeroMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 0;
        }
    }

    return matrix;
}

void scalarMultiply(int matrix[ROWS][COLS], int scalar, int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = matrix[i][j] * scalar;
        }
    }
}


void tambah_tambah(int matrik1[100][100], int matriks2[100][100], int panjang, int lebar, int hasil[100][100]) {
    for (int i = 0; i < panjang; i++) {
        for (int j = 0; j < lebar; j++) {
            hasil[i][j] = matrik1[i][j] + matriks2[i][j];
        }
    }
}

void tambah_kurang(int matrik1[100][100], int matriks2[100][100], int panjang, int lebar, int hasil[100][100]) {
    for (int i = 0; i < panjang; i++) {
        for (int j = 0; j < lebar; j++) {
            hasil[i][j] = matrik1[i][j] - matriks2[i][j];
        }
    }
}

void invers(int matriks[100][100], int panjang, int lebar, int transpose[100][100]) {
    for (int i = 0; i < panjang; i++) {
        for (int j = 0; j < lebar; j++) {
            transpose[j][i] = matriks[i][j];
        }
    }
    printf("Hasil Transpose:\n");
    for (int i = 0; i < lebar; i++) {
        for (int j = 0; j < panjang; j++) {
            printf("%d\t", transpose[i][j]);
        }
        printf("\n");
    }
}

void identitas(int matriks[100][100], int panjang, int lebar) {
    for (int i = 0; i < panjang; i++) {
        for (int j = 0; j < lebar; j++) {
            if (i == j) {
                matriks[i][j] = 1;
            } else {
                matriks[i][j] = 0;
            }
            printf("%d\t", matriks[i][j]);
        }
        printf("\n");
    }
}