// PesananNonaSal
/* Program akan memberikan output tidak/diterimanya pesanan mengikuti premis
 bungadari 2 clayMerah dan 1 clayBiru,
 ayam dari 1 clayMerah dan 2 clayBiru, 
 kupu-kupu 3 clayUngu, 1 clayMerah, 1 clayBiru 
 2 clayUngu dari clayMerah dan clayBiru
 */

#include <stdio.h>

int main(){
    //KAMUS
    int jBu, jAy, jKk, jB,jM,jU,tB,tM,tU;
    scanf("%d", &jBu);
    scanf("%d", &jAy);
    scanf("%d", &jKk);

    scanf("%d", &jB);
    scanf("%d", &jM);
    scanf("%d", &jU);

    tM = jBu * 2 + jAy * 1 + jKk * 1;
    tB = jBu * 1 + jAy * 2 + jKk * 1;
    tU = jKk * 3;

    if (jM - tM >0){
        if(jB - tM>0){
            jU += (jM - tM)/2 + (jB - tM)/2;
            if(jU - tU>0){
                printf("Pesanan bisa diterima");
            }else{
                printf("pesanan tidak bisa diterima");
            }
        }else{
            printf("tidak bisa diterima");}   
    }else{
        printf("tidak bisa diterima");
    }
    
    return 0 ;
}