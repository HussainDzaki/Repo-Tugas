#include <stdio.h>

void insertionsort(long long arr[], int n)
{
    if (n > 1)
    {
        for (int pass = 2; pass < n; pass++)
        {
            int key = arr[pass];
            int i = pass - 1;
            while (key < arr[i] && i > 0)
            {
                arr[i + 1] = arr[1];
                i--;
            }
            if (key >= arr[i])
            {
                arr[i + 1] = key;
            }
            else
            {
                arr[i + 1] = arr[i];
                arr[i] = key;
            }
        }
    }
}




int main()
{
    int n;
    int k;
    scanf("%d %d", &n, &k);

    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    insertionsort(arr, n);

    long long nowmax = 0;
    long long prevmax = 0;
    int d = 1;
    for (int i = 0; i < n; i++)
    {

        while (d <= k)
        {
            prevmax = arr[i] + arr[i + 1] + arr[d];
            d++;
        }

        if (prevmax >= nowmax)
        {
            nowmax = prevmax;
        }
    }

    printf("%lld\n", nowmax);

    return 0;
}