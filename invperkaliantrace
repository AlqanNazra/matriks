#include <stdio.h>
int main()
{
    int kolom1, baris1;
    
    
    printf("PROGRAM MATRIKS\n");
    printf("Syarat: Jumlah Kolom matriks pertama harus sama dengan jumlah baris matriks kedua\n");
    printf("MATRIKS PERTAMA\n");
    
    printf("\nMasukkan Jumlah Baris : ");
    scanf("%d",&baris1);

    printf("Masukkan Jumlah Kolom : ");
    scanf("%d",&kolom1);
    
    int A[baris1 + 1][kolom1 + 1];
    int temp;
    float B[baris1 + 1][kolom1 + 1];
    
    printf("Masukkan Nilai Matriks Pertama\n");
    for (int i = 1; i <= baris1; i++)
    {
        for (int j = 1; j <= kolom1; j++)
        {
            printf("A[%d][%d] = ",i,j);
            scanf("%d",&A[i][j]);
        }
    }

    printf("Matriks Pertama\n");
    for (int i = 1; i <= baris1; i++)
    {
        for (int j = 1; j <= kolom1; j++)
        {
                printf(" %d ",A[i][j]);
        }
        printf("\n");
    }

    float det,inv;

    printf("Invers Matriks \n");
    
    det = (A[1][1] * A[2][2]) - (A[1][2] * A[2][1]);
    if (det == 0)
    {
        printf("Matriks tidak memilikik invers");
    }
    else
    {

        temp = A[1][1];
        A[1][1] = A[2][2];
        A[2][2] = temp;

        A[1][2] = -A[1][2];
        A[2][1] = -A[2][1];
        for (int i = 1; i <= kolom1; i++)
        {
            for (int j = 1; j <= kolom1; j++)
            {
                B[i][j] = 1/det * A[i][j]; 
            }
            
        }
        
        for (int i = 1; i <= baris1; i++)
        {
            for (int j = 1; j <= kolom1; j++)
            {
                printf(" %f ",B[i][j]);
            }
            printf("\n");
            
        }
        
        
    }
    

}



#include <stdio.h>
int main()
{
    int kolom1, baris1;
    
    
    printf("PROGRAM MATRIKS\n");
    printf("Syarat: Jumlah Kolom matriks pertama harus sama dengan jumlah baris matriks kedua\n");
    printf("MATRIKS PERTAMA\n");
    
    printf("\nMasukkan Jumlah Baris : ");
    scanf("%d",&baris1);

    printf("Masukkan Jumlah Kolom : ");
    scanf("%d",&kolom1);

    int A[baris1 + 1][kolom1 + 1];
    
    printf("Masukkan Nilai Matriks Pertama\n");
    for (int i = 1; i <= baris1; i++)
    {
        for (int j = 1; j <= kolom1; j++)
        {
            printf("A[%d][%d] = ",i,j);
            scanf("%d",&A[i][j]);
        }
    }

    printf("Matriks Pertama\n");
    for (int i = 1; i <= baris1; i++)
    {
        for (int j = 1; j <= kolom1; j++)
        {
                printf(" %d ",A[i][j]);
        }
        printf("\n");
    }
    

    int kolom2,baris2;
    printf("MATRIKS KEDUA\n");

    printf("\nMasukkan Jumlah Baris : ");
    scanf("%d",&baris2);
    

    printf("Masukkan Jumlah Kolom : ");
    scanf("%d",&kolom2);

    while (kolom1 != baris2)
    {
    printf("KOLOM MATRIKS PERTAMA TIDAK SAMA DENGAN BARIS MATRIKS KEDUA!!!\n");
    printf("\nMasukkan Jumlah Baris : ");
    scanf("%d",&baris2);
    
    printf("Masukkan Jumlah Kolom : ");
    scanf("%d",&kolom2);
    

    }
    int B[baris2 + 1][kolom2 + 1];
    

    for (int i = 1; i <= baris2; i++)
    {
        for (int j = 1; j <= kolom2; j++)
        {
            printf("B[%d][%d] = ",i,j);
            scanf("%d",&B[i][j]);            
        }
        
    }

    printf("Matriks Kedua\n");
    for (int i = 1; i <= baris2; i++)
    {
        for (int j = 1; j <= kolom2; j++)
        {
                printf(" %d ",B[i][j]);
        }
        printf("\n");
    }
    

    int C[baris1 + 1][kolom2 + 1];

    for (int i = 1; i <= baris1; i++)
    {
        for (int j = 1; j <= kolom2; j++)
        {
            C[i][j] = 0;
            for (int k = 1; k <= baris2; k++)
            {
                
                C[i][j] = C[i][j] + (A[i][k] * B[k][j]);
            }
            
        }
        
    }
    printf("Hasil Perkalian Matriks Pertama dan Kedua\n");
    for (int i = 1; i <= baris1; i++)
    {
        for (int j = 1; j <= kolom2; j++)
        {
            printf(" %d ",C[i][j]);
        }
        printf("\n");
        
    }
    
    



}



#include <stdio.h>
int main()
{
    int kolom1, baris1,trace;
    
    
    printf("PROGRAM MATRIKS\n");
    printf("Syarat: Jumlah Kolom matriks pertama harus sama dengan jumlah baris matriks kedua\n");
    printf("MATRIKS PERTAMA\n");
    
    printf("\nMasukkan Jumlah Baris : ");
    scanf("%d",&baris1);

    printf("Masukkan Jumlah Kolom : ");
    scanf("%d",&kolom1);

    int A[baris1 + 1][kolom1 + 1];
    
    printf("Masukkan Nilai Matriks Pertama\n");
    for (int i = 1; i <= baris1; i++)
    {
        for (int j = 1; j <= kolom1; j++)
        {
            printf("A[%d][%d] = ",i,j);
            scanf("%d",&A[i][j]);
        }
    }

    printf("Matriks Pertama\n");
    for (int i = 1; i <= baris1; i++)
    {
        for (int j = 1; j <= kolom1; j++)
        {
                printf(" %d ",A[i][j]);
        }
        printf("\n");
    }

   
    trace = 0;

        if (baris1 == kolom1)
        {
            for (int i = 1; i <= baris1; i++)
            {
                for (int j = 1; j <= kolom1; j++)
                {
                    if (i == j)
                    {
                        trace = trace + A[i][j];
                    }
                    
                }
                
            }
            
        }
        else
        {
            printf("Matriks Bukan Persegi\nTrace Matriks Tidak Terdefinisi\n");
        }
        printf("Trace matriks = %d",trace);

    
    
}
