// BilanganUnikdanSuperUnik
/* Program akan mengatakan unik bila semua digit berbeda dan jumlah semua bilangannya ganjil
   bila memenuhi kriteria tersebut dan memenuhi 2 dari kriteria digit awal > digit akhir, bilangan bukan ganjil, 
   atau jumlah digit 2 dan 3 > digit 1  akan dikatakan Super Unik*/  

#include <stdio.h>

int main(){
    /*KAMUS*/
    /*Variabel*/
    int digit,d1,d2,d3,d4; // d1,d2,d3,d4 mewakilkan masing masing digit

    /*ALGORITMA*/
    printf("Masukkan sebuah bilangan: ");
    scanf("%d",&digit);
    
    /*Ekstraksi masing-masing digit*/
    d1 = digit / 1000;
    d2 = (digit - d1*1000) / 100;
    d3 = (digit - d1*1000 - d2*100) / 10;
    d4 = (digit - d1*1000 - d2*100 - d3*10);

    /*Membandingkan digit*/
    if ((d1 != d2 != d3 != d4) && ((d1+d2+d3+d4)%2 == 1)){
        if (d1 > d4 && (digit % 2 == 0) || (d1>d4 && ((d2 +d3)>d1)) || (digit % 2 == 0) && ((d2 +d3)>d1)){
            printf("Bilangan Super Unik");
        }else{
            printf("Bilangan Unik");
        }
    }else{
        printf("Bilangan biasa");
    }
    return 0;
}