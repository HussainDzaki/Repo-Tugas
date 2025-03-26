#include <stdio.h>

// Fungsi menghitung GCD
long long gcd(long long a, long long b)
{
    while (b != a)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a;
}

// Fungsi menghitung LCM
long long lcm(long long a, long long b)
{
    return (a * b) / (gcd(a, b));
}

// Fungsi menghitung GCD Array
long long gcdArray(long long arr[], int N)
{
    if (N == 0)
    {
        return 0;
    }
    else
    {
        long long gcdSekarang = arr[0];
        for (int i = 1; i < N; i++)
        {
            gcdSekarang = gcd(gcdSekarang, arr[i]);
            if (gcdSekarang == 0)
            {
                break;
            }
        }
        return gcdSekarang;
    }
}

long long lcmArray(long long arr[], int N)
{
    if (N == 0)
    {
        return 0;
    }
    else
    {
        long long lcmSekarang = arr[0];
        for (int i = 1; i < N; i++)
        {
            lcmSekarang = lcm(lcmSekarang, arr[i]);
            if (lcmSekarang == 0)
            {
                break;
            }
        }
        return lcmSekarang;
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    long long array[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &array[i]);
    }

    // menghitung skor awal
    long long gcdAwal = gcdArray(array, N);
    long long lcmAwal = lcmArray(array, N);
    long long nilaiMax = gcdAwal * lcmAwal;

    // iteratsi menghilangkan setiap elemen
    for (int i = 0; i < N; i++)
    {
        long long tempArr[N - 1];
        int index = 0;
        for (int j = 0; j < N; j++)
        {
            if (j != i)
            {
                tempArr[index++] = array[j];
            }
        }
        long long gcdTemp = gcdArray(tempArr, N - 1);
        long long lcmTemp = lcmArray(tempArr, N - 1);
        long long nilaiTemp = gcdTemp * lcmTemp;
        if (nilaiMax < nilaiTemp)
        {
            nilaiMax = nilaiTemp;
        }
    }

    printf("%lld\n", nilaiMax);
    return 0;
}
