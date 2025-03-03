//Membaca Sebuah Koordinat Titik
/*Membaca koordinat titik P dan menampilkannya dengan format (x,y)*/

#include <stdio.h>


//KAMUS
typedef struct {
    float x;
    float y;
} point;

int main(){
    point koor;
    
    // ALGORITMA
    scanf("%f", &koor.x);
    scanf("%f", &koor.y);
    printf("(%f, %f)", koor.x,koor.y);
    return 0;
}
