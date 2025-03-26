#include <stdio.h>

// Fungsi untuk menghitung GCD menggunakan algoritma Euclidean
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Fungsi untuk menghitung LCM dari dua bilangan
long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

// Fungsi untuk menghitung GCD dari seluruh array
long long compute_gcd(long long arr[], int N) {
    if (N == 0) return 0;
    long long current_gcd = arr[0];
    for (int i = 1; i < N; i++) {
        current_gcd = gcd(current_gcd, arr[i]);
        if (current_gcd == 1) break;
    }
    return current_gcd;
}

// Fungsi untuk menghitung LCM dari seluruh array
long long compute_lcm(long long arr[], int N) {
    if (N == 0) return 0;
    long long current_lcm = arr[0];
    for (int i = 1; i < N; i++) {
        current_lcm = lcm(current_lcm, arr[i]);
    }
    return current_lcm;
}

int main() {
    int N;
    scanf("%d", &N);
    long long arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }

    if (N == 0) {
        printf("0\n");
        return 0;
    }
    if (N == 1) {
        printf("%lld\n", arr[0] * arr[0]);
        return 0;
    }

    // Hitung skor awal tanpa menghilangkan elemen
    long long original_gcd = compute_gcd(arr, N);
    long long original_lcm = compute_lcm(arr, N);
    long long max_score = original_gcd * original_lcm;

    // Iterasi untuk menghilangkan setiap elemen
    for (int i = 0; i < N; i++) {
        long long temp_arr[N - 1];
        int index = 0;
        for (int j = 0; j < N; j++) {
            if (j != i) {
                temp_arr[index++] = arr[j];
            }
        }
        long long current_gcd = compute_gcd(temp_arr, N - 1);
        long long current_lcm = compute_lcm(temp_arr, N - 1);
        long long current_score = current_gcd * current_lcm;
        if (current_score > max_score) {
            max_score = current_score;
        }
    }

    printf("%lld\n", max_score);
    return 0;
}