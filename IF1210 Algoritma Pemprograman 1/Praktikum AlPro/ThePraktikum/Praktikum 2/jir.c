#include <stdio.h>

int main() {
    long long n, k;
    scanf("%lld %lld", &n, &k);
    for (int i = 0; i <= n; i++) {  // Loop hingga baris ke-n
        long long int val = 1;
        for (int j = 0; j <= i; j++) {
            // Cek apakah ini kombinasi yang diinginkan
            if (i == n && j == k) {
                printf("Kombinasi C(%lld, %lld) adalah %lld\n", n, k, val);
            }
            // Update nilai untuk kombinasi berikutnya dengan rumus yang benar
            val = val * (i - j) / (j + 1);
        }
    }
    return 0;
}