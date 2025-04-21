#include <stdio.h>

#define MAXN 5000
#define LL long long

int n, k;
LL a[MAXN];
int infected[MAXN];
int queue[MAXN];
int seeds[10]; // Maksimal k = 10 (dijaga kecil agar brute force bisa)
LL ans = -2000000000000000000LL; // Nilai awal minimum

// Fungsi untuk menghitung maksimum
LL max(LL a, LL b) {
    return a > b ? a : b;
}

// Fungsi untuk simulasi penyebaran virus (BFS manual)
LL bfs(int d) {
    int front = 0, back = 0;
    int i;

    // Inisialisasi array infected dan queue
    for (i = 0; i < n; i++) infected[i] = 0;

    LL sum_awal = 0;
    for (i = 0; i < d; i++) {
        int idx = seeds[i];
        infected[idx] = 1;
        queue[back++] = idx;
        sum_awal += a[idx];
    }

    int last = -1;

    while (front < back) {
        int now = queue[front++];
        last = now;

        if (now > 0 && infected[now - 1] == 0) {
            infected[now - 1] = 1;
            queue[back++] = now - 1;
        }
        if (now < n - 1 && infected[now + 1] == 0) {
            infected[now + 1] = 1;
            queue[back++] = now + 1;
        }
    }

    return sum_awal + a[last];
}

// Fungsi rekursif untuk menghasilkan kombinasi rumah awal
void kombinasi(int idx_mulai, int depth, int d) {
    int i;
    if (depth == d) {
        LL hasil = bfs(d);
        if (hasil > ans) ans = hasil;
        return;
    }

    for (i = idx_mulai; i < n; i++) {
        seeds[depth] = i;
        kombinasi(i + 1, depth + 1, d);
    }
}

int main() {
    int i, d;
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    // Coba semua jumlah rumah awal dari 1 sampai k
    for (d = 1; d <= k; d++) {
        kombinasi(0, 0, d);
    }

    printf("%lld\n", ans);
    return 0;
}