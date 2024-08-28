#include <iostream>
using namespace std;

int tambah_tambah (int matrik1[100][100],int matriks2[100][100],int panjang,int lebar)
{
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

int tambah_kurang (int matrik1[100][100],int matriks2[100][100],int panjang,int lebar)
{
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

int invers (int matriks[100][100],int panjang,int lebar)
{
    int tukar[100][100];
    int transpose[100][100];
    for (int i = 0; i < panjang; i++)
    {
        for (int j = 0;j < lebar;j++)
        {
            transpose[j][i] = matriks[i][j];
        }
    }
    cout << "hasil trapone" << endl;
    for (int i = 0; i < lebar; i++)
    {
        for (int j = 0;j < panjang;j++)
        {
      cout << transpose[i][j] << "\t";
    }
    cout << endl;
    }

    return transpose[100][100];
}


int indetitas (int matriks[100][100],int panjang,int lebar)
{
    for (int i = 0; i < panjang; i++)
    {
        for (int j = 0;j < lebar;j++)
        {
            if (i == j)
            {
            matriks[i][j] = 1;    
            }
            else
            {
            matriks[i][j] = 0;
            }
              cout << matriks[i][j] << "\t";
    }
    cout << endl;
    }
}

int main ()
{
        int panjang;
    int lebar;
   int a[100][100], transpose[100][100], row, column, i, j;
   
    cout << "Input jumlah baris: "; 
    cin >> panjang;
    cout << "Input jumlah kolom: "; 
    cin >> lebar;
    cout << endl;
   
    // cout << "\nMasukkan angka: " << endl;
   
    // for (int i = 0; i < panjang; ++i) {
    //     for (int j = 0; j < lebar; ++j) {
    //         cout << "Masukkan element " << i + 1 << "," << j + 1 << ": ";
    //         cin >> a[i][j];
    //     }
    // }
    

}