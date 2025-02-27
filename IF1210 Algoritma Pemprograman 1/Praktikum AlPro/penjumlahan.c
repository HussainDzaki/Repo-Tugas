/*Program Penjumlahan*/
/*Menjumlahkan tiga masukan bilangan real (float) r*/

#include <stdio.h>

int main () {
    /*KAMUS*/
    float r1;
    float r2;
    float r3;
    float rt;

    /*ALGORITMA*/
    scanf("%f", &r1);
    scanf("%f", &r2);
    scanf("%f", &r3);

    rt = r1+r2+r3;

    printf("%f\n", rt);

    return 0;

}