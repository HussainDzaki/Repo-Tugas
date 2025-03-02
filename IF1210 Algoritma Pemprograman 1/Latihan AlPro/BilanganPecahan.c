// SelisihPecahan
// Spesifikasi Program : Memvalidasi dan mencari selisih pecahan dan memasukiny dalam tipe pechan


//KAMUS
#include <stdio.h>
typedef struct
{
    int pembilang; 
    int penyebut; // penyebut > 0
    
} pecahan;

int main(){
    pecahan P1, P2, P3;
    int penyebutbaru, pembilangbaru;
    
    //ALGORITMA
    scanf("%d", &P1.pembilang);
    scanf("%d", &P1.penyebut);
    scanf("%d", &P2.pembilang);
    scanf("%d", &P2.penyebut);

    penyebutbaru = P1.penyebut * P2.penyebut;
    if (penyebutbaru > 0){
        P3.penyebut = penyebutbaru;
        pembilangbaru = P1.pembilang * P2.penyebut - P2.pembilang * P1.penyebut;
        if (pembilangbaru < 0){
            pembilangbaru = pembilangbaru * -1;
            P3.pembilang = pembilangbaru;
        }else { // penyebut > 0
            P3.pembilang = pembilangbaru;
        
        }
        printf("Maka hasil dari selisihnya adalah %d/ %d", P3.pembilang, P3.penyebut);
    }else{ // salah satu yang dimasukan  ada 0
        printf("Masukan tidak valid");
    }
    return 0 ;
}

// a/b - c/d = a*d - b*c / b*d 