// MenghitungJarak
// Meminta input v dalam m/s dan t dalam sekon dan menghitung jarak dengan s = v*t

// KAMUS
#include <stdio.h>

int main(){
    float v,t,s;
    // ALGORITMA
    scanf("%f", &v);
    scanf("%f", &t);
    s= v*t;
    printf("%f", s);
    return 0;

}