#include <stdio.h>

void putarkanan(int arr[], int n, int put){
    for (int i = 0; i < (put % n); i++)
    {
        int temp = arr[n-1];
        for (int j = n; j > 0; j--)
        {
            arr[j] = arr[j-1];
        }
        arr[0] = temp;
    }
    
}

void printArr(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i < n-1)
        { 
            printf(" ");
        }
        
    }
    printf("\n");
}


int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    putarkanan(arr, n , k);
    printArr(arr,n);
    return 0;
    
    
}