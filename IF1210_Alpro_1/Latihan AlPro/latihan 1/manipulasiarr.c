#include <stdio.h>

#define CAPACITY 100

typedef struct Arrayku
{
    int arr[CAPACITY];
    int nEff;
} arrku;


void createarr(arrku *arr){
    for (int i = 0; i < CAPACITY; i++)
    {
        /* code */
    }
    
}

void sisip(int *A , int val, int n){
    for (int i = 0; i < n; i++)
    {
        A[i + 1] = A[i];
    }   
}

void printarr(int *A, int n){
    print("[");
    for (int i = 0; i < n; i++){
        printf("%d", A[i]);
        if (i < n -1){
            printf(",");
        }  
    }
    printf("]");
    
}

int main(){
    int array[5]

    
}