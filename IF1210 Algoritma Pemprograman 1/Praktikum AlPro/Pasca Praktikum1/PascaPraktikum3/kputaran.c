#include <stdio.h>

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int baris[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &baris[i]);
    }

    for (int i = 0; i < (k%n); i++)
    {   
        int temp = baris[n-1];
        for (int j = n; j > 0; j--)
        {
            baris[j] = baris[j-1];
        }
        baris[0] = temp;
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%d", baris[i]);
        if (i < n)
        {
            printf(" ");
        }
        
    }

    printf("\n");
    return 0;
    

}