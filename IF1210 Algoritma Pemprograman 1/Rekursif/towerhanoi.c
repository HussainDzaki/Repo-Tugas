
#include <stdio.h>
void pm(int awal, int akhir){
    printf("%d -> %d\n", awal , akhir);
}
void hanoi(int n, int awal, int akhir){
    int rodlain;
    if (n == 1)
    {
        pm(awal, akhir);
    }
    else
    {
        rodlain = 6 - (awal+ akhir); // rod referensi perpindahan
        hanoi(n-1, awal, rodlain); // memindahkan ke bagian lain
        pm(awal,akhir); // memindahkan rod terbesar ke akhir
        hanoi(n-1, rodlain, akhir); // memindahkan rod bagian lain ke akhir
    }
    
}

int main(){
    hanoi(3,1,2);

    return 0;
}