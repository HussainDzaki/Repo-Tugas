// JarakTempuh
// Menghitung jarak tempuh dimana v,t>0; v = float, t=int

#include <stdio.h>
#define PI = 3.14149
int main(){
    // KAMUS
    int t;
    float v,s;

    // ALGORITMA
    scanf("%f", &v);
    scanf("%d", &t);
    s = v*t;
    printf("%0.2f\n", s);
    return 0;

}