#ifndef TEKATEKI_H
#define TEKATEKI_H

#include <stdio.h>

/**
 * Fungsi untuk menghitung kombinasi C(n, k) = n! / (k! * (n - k)!)
 * Note: jangan menggunakan perhitungan faktorial secara langsung,
 * tetapi sederhanakan bentuk perhitungan kombinasi
 * @param n int
 * @param k int
 * @return Mengembalikan hasil kombinasi C(n, k) dalam bentuk long long
 */
long long kombinasi(int n, int k)
{
    for (int i = 0; i <= n; i++) {  // Loop hingga baris ke-n
        long long int val = 1;
        for (int j = 0; j <= i; j++) {
            // Cek apakah ini kombinasi yang diinginkan
            if (i == n && j == k) {
                return val;
            }
            // Update nilai untuk kombinasi berikutnya dengan rumus yang benar
            val = val * (i - j) / (j + 1);
        }
    }
    return 0;
}
    


/**
 * Fungsi untuk menghitung bilangan Catalan ke-N
 * Catalan(N) = C(2N, N) / (N + 1)
 * @param n int
 * @return Mengembalikan Catalan(n)
 */
long long catalan(int n){
    return kombinasi(2*n, n) / (n +1);
}
    
#endif
