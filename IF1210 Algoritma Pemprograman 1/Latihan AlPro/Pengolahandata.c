#include <stdio.h>

void insertionsort(int arr[], int n){
    if (n > 0)
    for (int pass = 0; pass < n; pass++)
    {
        int key = arr[pass];
        int i = pass - 1;
        while (key < arr[i] && i > 0)
        {
            arr[i+1] = arr[i];
            i = i -1;
        }

        if (key >= arr[i])
        {
            arr[i+1] = key;
        }else
        {
            arr[i+1] = arr[i];
            arr[i] = key;
        }
        
        
        
    }
    
}

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


int modusArr(int arr[], int n){
    insertionsort(arr, n);
    int frekMax = 1;
    int frektemp = 1;
    int key = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[i-1])
        {
            frektemp++;
        }
        else
        {
            frektemp = 1;
        }

        if (frektemp> frekMax)
        {
            frekMax = frektemp;
            key = arr[i];
        } 
    }
    return key;
}

int maxArr(int arr[], int n){
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (max <= arr[i])
        {
            max = arr[i];
        }
        
    }
    return max;
    
}

void reverseArr(int arr[], int n){
    int awal = 0;
    int akhir = n-1;
    while (awal < akhir)
    {
        int temp = arr[awal];
        arr[awal] = arr[akhir];
        arr[akhir] = temp;
        awal++;
        akhir--;
    }
    
}


int main(){
    int arr[7] = {1 , 5 ,7 ,9, 3 , 1 ,999999};
    insertionsort(arr,7);
    printArr(arr, 7);
    printf("%d\n", maxArr(arr,7) ) ;
    reverseArr(arr, 7);
    printArr(arr, 7);
    return 0;
}