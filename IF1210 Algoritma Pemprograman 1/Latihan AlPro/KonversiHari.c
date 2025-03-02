// Mengkonversi angka kedalam format hari, jam, menit dan detik
/* algortimanya Hari teridiri dari 86400 detik, jam terdiri dari 3600 detik,
   menit teridir dari 60 detik */ 

#include <stdio.h>
int main(){
    // KAMUS
    int unsigned t,tawal, hari, jam,menit,detik;
    // ALGORITMA
    scanf("%d", &t); 
    tawal = t;
    hari = t / 86400; 
    t = t % 86400;  
    jam = t / 3600; 
    t = t % 3600;
    menit = t / 60;
    detik = t % 60;
    printf("Maka dari %d angka detik menjadi %d hari, %d jam, %d menit, %d detik", tawal,hari,jam, menit,detik);
    return 0 ;
}