#include <stdio.h>
int total = 0;
// TODO: Perbaiki prosedur agar variabel total bisa diperbarui secara langsung
void countPrime(int A, int B, int *total)
{   
    for (int i = A; i <= B; i++){
        if(i <= 1){
            continue;
        }
        int cek = 1;
        for(int j = 2; j < i; j++){
            if (i % j == 0){
                cek = 0;
                break;
            }
        }
        if(cek == 1){
            (*total)++;
        }
    }
    
}



int main()
{
    int A, B, total = 0;

    scanf("%d %d", &A, &B);
    // TODO: Baca dua bilangan integer A dan B dalam satu baris
    // Input harus dalam format: "A B"

    // TODO: Perbaiki pemanggilan prosedur dengan menggunakan alamat variabel total
    // Agar perubahan nilai di dalam prosedur juga mempengaruhi nilai di main()
    countPrime(A, B, &total);
    printf("%d\n", total);
    return 0;
}