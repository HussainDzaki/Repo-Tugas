#include <stdio.h>

int main(){
    // KAMUS
    int jPeng, jKom, hPeng,hKom,kPeng, tPeng, tKom;

    //ALGORITMA
    printf("Banyak uang Peng yang ditawarkan: ");
    scanf("%d", &jPeng);
    printf("Banyak uang Kom yang ditawarkan: ");
    scanf("%d", &jKom);
    printf("Konversi mata uang Peng ke rupiah: ");
    scanf("%d", &hPeng);
    printf("Konversi mata uang Peng ke rupiah: ");
    scanf("%d", &hKom);

    tPeng = jPeng * hPeng;
    tKom = jKom * hKom;

    if (tPeng > tKom){
        printf("Adik Tuan Leo memilih Peng.");
    }
    else{
        printf("Adik Tuan Leo memilih yang Kom.");
    }

}