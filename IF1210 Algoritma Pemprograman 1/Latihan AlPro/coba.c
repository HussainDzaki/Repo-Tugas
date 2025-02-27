#include <stdio.h>

int main() {
    int angka1, angka2, hasil;

    // Meminta input pertama
    printf("Masukkan angka pertama: ");
    scanf("%d", &angka1);

    // Meminta input kedua
    printf("Masukkan angka kedua: ");
    scanf("%d", &angka2);

    // Menghitung hasil penjumlahan
    hasil = angka1 + angka2;

    // Menampilkan hasil
    printf("Hasil penjumlahan: %d\n", hasil);

    return 0;
}