// Program Mengeluarkan Bilangan terbesar
/*Membandingkan variabel x dan y kemudian mengeluarkan bilangan terbesar*/

#include <stdio.h>
int main(){
    /*KAMUS*/
    float x,y;

    /*ALGORITMA*/
    printf("Masukka x: ");
    scanf("%f", &x);
    printf("Masukka y: ");
    scanf("%f", &y);
    printf("Yang terbesar adalah : ");
    if (x>y){printf("%f", x);}
    else{printf("%f", y);
    }

    return 0;
}