#include <stdio.h>
typedef struct 
{
    int DD;
    int MM;
    int YY;

}Tanggal;

// NOMOR 1
float Max2(int a, int b ){
    // diberikan a dan b menghasilkan a jika a>=b dan b jika b>= a
    // KAMUS LOKAL
    // ALGORITMA
    if (a>= b){
        return a;
    }
    else // b>= a
    {
        return b;
    }
    

}

float Max3(int a, int b, int c){
    // diberikan a,b,c menghasilkan a jika a>= b dan a >= c, menghasilkanb jika b>= a dan b>= c dan menghasilkan c jika c >= a dan c >= b
    // KAMUS LOKAL
    // function Max2(a,b) -> float
    // Membandingkan a dan b mengeluarkan bilangan paling besar
    
    // ALGORITMA
    return Max2(max2(a,b),c);
}

// NOMOR 2
Tanggal Nextday(Tanggal Date){
    // menerima data type Tanggal dan menghasilkan tanggal besok dari Tanggal
    
    // KAMUS LOKAL 
    // Kabisat(yy) -> boolean
    // Diberikan tahun mengoutput true jika tahun itu tahun kabisat 
    
    // ALGORITMA
    if (Date.MM == 2){
        if(Date.DD < 28){
            Date.DD += 1 ;
            return(Date);}
        else if(Date.DD == 28){
            if( kabisat(Date.YY) == 1){
                Date.DD += 1 ;
                return(Date) ;}
            else{
                Date.DD = 1; Date.MM += 1 ;
                return(Date) ;}}
        else if (Date.DD == 29){
            Date.DD = 1; Date.MM += 1;
            return(Date);}
        else{ 
            printf("Terjadi Kesalahan");}}
    else if (Date.MM == 12){
        if(Date.DD < 31){
            Date.DD += 1;
            return(Date);}
        else if (Date.DD == 31){
            Date.DD = 1; Date.MM =1, Date.YY += 1;
            return(Date);}
        else{ printf("Terjadi Kesalahan");}
    }
    else if ((Date.MM == 1) ||( Date.MM == 3)||(Date.MM == 5) || (Date.MM == 7) ||(Date.MM == 8)|| (Date.MM == 10) ){
            if (Date.DD < 31){
                Date.DD += 1;
                return Date;} 
            else{
                Date.DD = 1 ; Date.MM += 1;
                return Date;}}
    else if ( (Date.MM == 4) || (Date.MM == 6)|| (Date.MM == 9)|| (Date.MM == 11)){
                if (Date.DD < 30){
                    Date.DD += 1;
                    return Date;}
                else{
                    Date.DD = 1 ; Date.MM += 1;
                return Date;}}
    else(printf("terjadi kesalahan"));
    
}

// NOMOR 3
void Tukar(int a, int *b){
    /* I.S : diberikan a = A dan b = B 
       F.S : a = B dan b = A  */

    // KAMUS LOKAL
    int temp;

    // ALGORRITMA
    temp = a;
    a = b;
    b = temp; 
}

void Putar3bil(int *a, int *b, int *c){
    /* I.S : diberikan a = A, b = B, c = C
       F. S : a = C, b = A, c = B */

    // KAMUS LOKAL
    // procedure Tukar(input/output a,b : integer)
    /* menukar a, b menjadi b, a */

    // ALGORITMA 
    Tukar(a,c);
    Tukar(b,c);
}