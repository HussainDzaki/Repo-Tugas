// KelilingLingkaran
// Menghitung keliling lingkaran berdasarkan masukan jari-jari

//KAMUS
#include <stdio.h>
int main(){
    const float PI = 3.14159;
    float r, kel;

    //ALGORITMA
    scanf("%f", &r);
    kel = 2 * PI * r;
    printf("%f", kel);
    return 0;
}