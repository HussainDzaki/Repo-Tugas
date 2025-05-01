#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

/**
 * @brief Mengurutkan array dalam urutan menaik.
 * @funfact, array pada sebuah parameter sudah di pass berupa pointer ke elemen pertama, sehingga modifikasi pada array akan mengubah nilai aslinya
 * @param arr Array yang akan diurutkan.
 * @param n Jumlah elemen dalam array.
 */
void sort(int arr[], int n)
{
    // menggunakan insertion sort

    // memulai dari element kedua
    for (int i = 1; i < n; i++){
        int temp = arr[i];
        int j = i - 1;
        // mengeser elmen array [0.. i -1] yang lebih besar dari temp
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = temp;
    }
}

/**
 * @brief Menemukan indeks pertama elemen target dalam array.
 *
 * @param arr Array yang akan dicari.
 * @param n Jumlah elemen dalam array.
 * @param target Elemen yang dicari.
 * @return Indeks elemen target, atau -1 jika tidak ditemukan.
 */
int find(int arr[], int n, int target)
{

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Menghitung rata-rata elemen dalam array.
 *
 * @param arr Array elemen.
 * @param n Jumlah elemen dalam array.
 * @return Rata-rata elemen.
 */
double calculateAverage(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return (double)sum / n;
}

/**
 * @brief Menemukan median dari elemen dalam array (dibulatkan).
 *
 * @param arr Array elemen.
 * @param n Jumlah elemen dalam array.
 * @return Median dari elemen.
 */
int findMedian(int arr[], int n)
{
    sort(arr, n);
    if (n % 2 == 0) {
        return (arr[n/2 - 1] + arr[n/2]) / 2;
    } else {
        return arr[n/2];
    }
}

/**
 * @brief Menemukan modus dari elemen dalam array.
 *
 * @param arr Array elemen.
 * @param n Jumlah elemen dalam array.
 * @return Modus dari elemen, atau elemen pertama jika semua elemen memiliki frekuensi yang sama.
 */
int findMode(int arr[], int n)
{
    if (n == 0)
    {
        return -1;
    }

    sort(arr, n);
    int modus = arr[0];
    int frekMax = 1;
    int frekTemp = 1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            frekTemp++;
        }
        else
        {
            frekTemp = 1;
        }
        if (frekTemp > frekMax)
        {
            frekMax = frekTemp;
            modus = arr[i];
        }

        
    }
    return modus;
}

/**
 * @brief Menemukan elemen maksimum dalam array.
 *
 * @param arr Array elemen.
 * @param n Jumlah elemen dalam array.
 * @return Elemen maksimum dalam array.
 */
int findMax(int arr[], int n)
{
    sort(arr, n);
    return arr[n - 1];
}

/**
 * @brief Menemukan elemen minimum dalam array.
 *
 * @param arr Array elemen.
 * @param n Jumlah elemen dalam array.
 * @return Elemen minimum dalam array.
 */
int findMin(int arr[], int n)
{
    sort(arr, n);
    return arr[0];
}

/**
 * @brief Membalikkan elemen dalam array.
 *
 * @param arr Array yang akan dibalik.
 * @param n Jumlah elemen dalam array.
 */
void reverseArray(int arr[], int n)
{
    int awal = 0;
    int akhir = n - 1;
    while (awal < akhir)
    {
        int temp = arr[awal];
        arr[awal] = arr[akhir];
        arr[akhir] = temp;
        awal++;
        akhir--;
    }
}

#endif