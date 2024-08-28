#include <stdio.h>

int tambah_tambah (int matrik1[100][100],int matriks2[100][100])
{
    int panjang;
    int lebar;
    int hasil[100][100];
    for (int i = 0; i < panjang ;i++)
    {
        for(int j = 0; j < lebar;j++)
        {
            hasil[i][j] = matrik1[i][j] + matriks2 [i][j];
        }
    }
    return hasil[100][100];
}

int tambah_kurang (int matrik1[100][100],int matriks2[100][100])
{
    int panjang;
    int lebar;
    int hasil[100][100];
    for (int i = 0; i < panjang ;i++)
    {
        for(int j = 0; j < lebar;j++)
        {
            hasil[i][j] = matrik1[i][j] - matriks2 [i][j];
        }
    }
    return hasil[100][100];
}