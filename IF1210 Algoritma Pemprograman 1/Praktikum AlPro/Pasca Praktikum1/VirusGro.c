#include <stdio.h>

void insertionsort(long long arr[], int n) {
    for (int pass = 1; pass < n; pass++) {  // Start from 1
        long long key = arr[pass];
        int i = pass - 1;
        
        // Move elements greater than key to one position ahead
        while (i >= 0 && arr[i] < key) {  // Changed to '>' for descending
            arr[i + 1] = arr[i];  // Fixed the copying bug
            i--;
        }
        arr[i + 1] = key;  // Simplified insertion
    }
}

int main()
{
    int n;
    int k;
    scanf("%d %d", &n, &k);

    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    insertionsort(arr, n);

    long long jumlah_iterasi_awal[n+1];
    jumlah_iterasi_awal[0] = 0; // index dummy
    for (int i = 0; i < n; i++)
    {
        jumlah_iterasi_awal[i+1] = jumlah_iterasi_awal[i] + arr[i];
    }

    // Menghitung kombinasi untuk pilihan d

    long long nilai_maxtersisa[n];
    nilai_maxtersisa[n-1] = arr[n-1];
    for (int i = n-2 ; i >= 0; i--){
        if (arr[i] > nilai_maxtersisa[i+1])
        {
            nilai_maxtersisa[i] = arr[i];
        }
        else
        {
            nilai_maxtersisa[i] = nilai_maxtersisa[i+1];
        }
        
    }
    
    long long nilai_eff = -999999;
    for (int d = 1; d <= k; d++){
        long long eff = jumlah_iterasi_awal[d]+ nilai_maxtersisa[d];
        if (eff > nilai_eff)
        {
            nilai_eff = eff;
        }
        
        
    }

    printf("%lld\n", nilai_eff);
    
    
    return  0 ;
}