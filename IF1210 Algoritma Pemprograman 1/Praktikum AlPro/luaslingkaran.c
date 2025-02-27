/*Program LuasLingkaran*/
/*Menghitung luas lingkaran dengan rumus Area = 3.1415*r*r*/

#include <stdio.h>

int main (){
    /*KAMUS*/
    const float PI = 3.1415;
    float r;
    float area;

    /*ALGORITMA*/
    scanf("%f", &r);

    area = PI*r*r;

    printf("%f\n", area);
    return 0;
}