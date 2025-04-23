// Mencari GCD 
// program ini akan mencari greatest commin dividor dari 2 bilangan
#include <stdio.h>

int main(){
    // KAMUS 
    long int a;
    long int b ;
    // Algortima euclidean Algorithm
    scanf("%ld", &a);
    scanf("%ld", &b);
    // Menerapkan 
    while( a != b){
        if (a > b){
            a = a - b;
        }
        else{
            b = b -a;
        }
    }
    printf("%ld\n",a);
    return 0;
}