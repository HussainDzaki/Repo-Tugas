#include <stdio.h>

void memerikanindex(int deret[], int n, int target){
    int val1, val2;
    for (int i = 0; i < n; i++)
    {   
        val1 = deret[i];
        int j = 0;
        while ( j< n)
        {   

            if ((deret[i] + deret[j] == target )&& i != j)
            {
                printf("[%d, %d]\n", i,j);
            }
            j++;
            if (val1 == deret[j]){
                break;
            }
        }
        
        
    }
    
}

int main(){
    int n, tar;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &tar);
    memerikanindex(arr,n,tar);
    
}