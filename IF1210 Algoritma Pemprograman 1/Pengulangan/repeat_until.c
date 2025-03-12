// Program TulisBil2



#include <stdio.h>
int main(){
    //KAMUS
    int N, i, sums;

    // ALGORITMA 
    i = 1;  // inisiasi
    sums = 0;
    scanf("%d", &N);
    
    do{
        printf("%d\n", i);
        sums = sums + i ; 
        i++;
    } while (i <= N);

    printf("Total bulangannya adalah %d", sums);

    return 0;
 
}