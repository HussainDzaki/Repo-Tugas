//MemghitungTotalKelereng
//Menghitungtotal harga kelereng dari user

//KAMUS
#include <stdio.h>
int main(){
    const int hMe = 10;
    const int hHi = 15;
    const int hKu = 20;
    int m,h,k, tot;

    // ALGORITMA
    scanf("%d", &m);
    scanf("%d", &h);
    scanf("%d", &k);

    tot = hMe * m + hHi * h + hKu *k;

    printf("%d", tot);
    return 0;
}