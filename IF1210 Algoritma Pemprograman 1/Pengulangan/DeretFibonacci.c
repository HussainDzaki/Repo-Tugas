// Deret Fibonacci
// Program akan meminta masukan banyak bilangan fibonaci dan mengeluarkan angka fibonacinya

#include <stdio.h>

int main(){
    // KAMUS
    int N, i,a,b,c; 

    // Algoritma
    // Inisasi Variabel
    i = 0; 
    a = 0;
    b = 1;
    c = 0;
    scanf("%d", &N);
    printf("%d",a);
    while(i < N-1){
        printf(" ");
        a = b; 
        b = c;
        c = a + b; 
        i++;
        printf("%d", c);

    }
    printf("\n");
    return 0 ;
}