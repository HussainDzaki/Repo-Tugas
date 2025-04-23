#include <stdio.h>

int binarySearch(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;
    int result = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            result = mid;
            right = mid - 1; // Cari di sebelah kiri untuk indeks terkecil
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return result;
}

void printindex(int arr[], int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i < n - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

int main()
{
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    int Q;
    scanf("%d", &Q);
    int arrhasil[Q];
    for (int i = 0; i < Q; i++)
    {
        int target;
        scanf("%d", &target);
        int index = binarySearch(arr, N, target);
        arrhasil[i] = index;
    }

    printindex(arrhasil, Q);

    return 0;
}