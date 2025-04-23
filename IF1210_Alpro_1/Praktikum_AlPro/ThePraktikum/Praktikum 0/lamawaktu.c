// Menghitung lama waktu
/* Menghitung Lama waktu dari dua masukan HH, MM, SS*/

#include <stdio.h>
// KAMUS
typedef struct 
{
    int HH;
    int MM;
    int SS;
} waktu;

int main(){
    waktu p1,p2, p3;
    //ALGORITMA
    /*Mendapatkan input 2 waktu*/
    scanf("%d %d %d", &p1.HH, &p1.MM, &p1.SS);
    scanf("%d %d %d", &p2.HH, &p2.MM, &p2.SS);

    p3.HH = p2.HH - p1.HH;
    p3.MM = p2.MM - p1.MM;
    p3.SS = p2.SS - p1.SS;

    printf("%d %d %d\n", p3.HH,p3.MM,p3.SS);
    return 0 ;
}