#include <stdio.h>

void Sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int temp = arr[n-1];
        for (int j = i; j < n; j++)
        {
            if (arr[j] <= temp)
            {
                temp = arr[j];
            }
            
        }
        arr[i] = temp;
    }
}

int main(){
    int arr[5] = {1, 5, 3,2, 1};
    Sort(arr, 5);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}