#include <stdio.h>

void insertionsort(int arr[], int n){
    if (n > 0)
    {
        for (int pass = 1; pass < n; pass++)
        {
            int key = arr[pass];
            int index = pass - 1;
            while (key > arr[index] && index > 0)
            {
                arr[index + 1] = arr[index];
                index = index - 1 ;
            }
            if (key <= arr[index])
            {
                arr[index+1] = key;
            }
            else{
                arr[index + 1] = arr[index];
                arr[index] = key; 
            }
            
            
            
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


int main(){
    int arr[7] = {1 , 5 ,7 ,9, 3 , 1 ,999999};
    insertionsort(arr,7);
    printArr(arr, 7);
    printf("%d", maxArr(arr,7) ) ;
    return 0;
}