#include <stdio.h>

void rotasiKanan(int N, int k, int arr[])
{
    for (int rot = 0; rot < k; rot++)
    {
        int temp = arr[N - 1];
        for (int i = N; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = temp;
    }
}

void rotasiKiri(int N, int k, int arr[])
{
    for (int rot = 0; rot < k; rot++)
    {
        int temp = arr[0];
        for (int i = 0; i < N - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[N - 1] = temp;
    }
}

void printbaris(int arr[], int N)
{
    printf("[");
    for (int i = 0; i < N; i++)
    {
        printf("%d", arr[i]);
        if (i < N - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

int main()
{
    int N, k;
    scanf("%d", &N);
    scanf("%d", &k);

    int arr[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    int arrTemp[N];

    for (int i = 0; i < k; i++)
    {
        int rot;
        scanf("%d", &rot);
        rotasiKanan(N,rot, arr);
        printbaris(arr, N);
        rotasiKiri(N, rot, arr);
    }

    return 0;
}