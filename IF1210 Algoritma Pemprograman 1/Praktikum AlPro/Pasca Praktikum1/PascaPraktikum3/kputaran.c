#include <stdio.h>

int main(){
    long long n, k;
    scanf("%lld %lld", &n, &k);
    long long baris[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &baris[i]);
    }

    for (long long i = 0; i < (k%n); i++)
    {   
        long long temp = baris[n-1];
        for (long long j = n; j > 0; j--)
        {
            baris[j] = baris[j-1];
        }
        baris[0] = temp;
    }
    
    for (long long i = 0; i < n; i++)
    {
        printf("%lld", baris[i]);
        if (i < n-1)
        {
            printf(" ");
        }
        
    }

    printf("\n");
    return 0;
    

}