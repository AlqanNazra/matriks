#include <stdio.h>
#include "skalar.c"
#include "matriks_nol.c"
#include "tamhur.cpp"
#include "ukuran.cpp"

// Function declarations
void inverseMatrix();
void multiplyMatrices();
void traceMatrix();

int main() {
    int choice;

    do {
        printf("\nPROGRAM OPERASI MATRIKS\n");
        printf("1. Invers Matriks (2x2)\n");
        printf("2. Perkalian Dua Matriks\n");
        printf("3. Trace Matriks\n");
        printf("4. Keluar\n");
        printf("Pilih operasi (1-4): ");
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
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid, silakan coba lagi.\n");
        }
    } while (choice != 4);

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
