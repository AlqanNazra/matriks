#include <stdio.h>

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