#include <stdio.h>

void targetsum(long long arr[], long long target, int n)
{
    if (n > 1)
    {
        for (long long i = 0; i < n; i++)
        {
            for (long long j = 0; j < i; j++)
            {
                if ((arr[i] + arr[j] == target) && i != j)
                {
                    printf("[%lld, %lld]\n", j, i);
                    break;
                    
                }
            }
            break;
        }
    }
}

int main()
{
    int n, target;
    long long bil;
    scanf("%d", &n);
    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    scanf("%d", &target);
    targetsum(arr, target, n);
}