#include <stdio.h>

void printArr(int arr[], int n){
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i < n -1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

void rotasiKanan(int arr[], int n, int rot){
    for (int i = 0; i < (rot%4); i++)
    {   
        int temp = arr[n-1];
        for (int j = n; j > 0; j--){
            arr[j] = arr[j-1];}
        arr[0] = temp;
    }
}

void rotasiKiri(int arr[], int n, int rot){
    for (int i = 0; i < (rot%4); i++)
    {   
        int temp = arr[0];
        for (int j = 0; j < n; j++)
        {
            arr[j] = arr[j +1];
        }
        arr[n-1] = temp;
        
    }
    
}
int main(){
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    int barisan[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &barisan[i]);
    }
    int rotasi;
    for (int i = 0; i < k; i++)
    {
        scanf("%d",&rotasi );
        rotasiKanan(barisan, n, rotasi);
        printArr(barisan, n);
        rotasiKiri(barisan, n, rotasi);
    }
    

    return 0;
    
    
}