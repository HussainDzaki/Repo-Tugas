#include <stdio.h>
#define NMAX 100

typedef struct tTabInt
{
    int Tab[NMAX];
    int Neff; /* index efektif tabel, 0 <= Neff <= Nmax */
} TabInt;

void SEQSearchX1(TabInt T, int N, int X, int *IX)
{
    /* Mencari Harga X dalam dabel T [1..N] secara sekuensial. Hasilinya index IX, T(IX] = X (i terkecil), IX = 0 Jika tidak ketemu */
    /* KAMUS */
    int i;
    /* ALGORITMA */
    i = 1;
    while (i < N && T.Tab[i] != X) /* JIKA T KOSONG MAKA T.TAB[i] AKAN MENGHASILKAN ERROR*/
    {
        i += 1;
    }
    if (T.Tab[i] == X)
    {
        *IX = i;
    }
    else
    {
        *IX = 0;
    }
}


void SEQSearchX2(TabInt T, int N, int X, int *IX, int *Found){ /* FOUND BOOLEAN */
    /* Mencari harga X dalam tabel T secara sekuensial. Hasilnya adalah index IX dimana T[IX] = X (i terkecil)
       IX = 0 jika tidak ketemu dan sebuah boolean Found (True jika ketemu) */

    /* KAMUS LOKAL */
    int i ;

    /* ALGORITMA */
    *Found = 0;
    i = 1;
    while (i <= N && (!Found)) /* T BOLEH KOSONG KARENA TIDAK AD PEMERIKSAAN T.Tab[i]*/
    {
        if (T.Tab[i] == X){
            *Found = 1;
        }else{
            i += 1;
        }
    }
    /* i > N or Found*/

    if (Found){
        *IX = i;
    }else{
        *IX = 0;
    }
    
}


int main()
{
    int IX;
    TabInt T1;
    T1.Neff = 10;
    SEQSearchX1(T1, T1.Neff, 100, &IX);
    printf("%d\n", IX);
}


