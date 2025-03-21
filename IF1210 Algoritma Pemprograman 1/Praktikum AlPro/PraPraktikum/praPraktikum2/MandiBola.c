#include <stdio.h>


int HitungBiayaTiket(int jumlah_anak, int jumlah_dewasa, int jumlah_lansia)
{
    return jumlah_anak * 10000 + jumlah_dewasa * 20000 + jumlah_lansia * 15000;
}

void PrintTiket(int jumlah_anak, int jumlah_dewasa, int jumlah_lansia)
{
    printf("Tiket berhasil dibeli!\n");
    printf("Rincian:\n");
    printf("- Jumlah anak-anak: %d\n", jumlah_anak);
    printf("- Jumlah dewasa: %d\n", jumlah_dewasa);
    printf("- Jumlah lansia: %d\n", jumlah_lansia);
    printf("- Total biaya: %d\n", HitungBiayaTiket(jumlah_anak, jumlah_dewasa, jumlah_lansia));
}
void SelamatDatang(int input)
{
    int dewasa, ank2, lansia;

    lansia = input / 100;
    dewasa = input / 10 % 10;
    ank2 = input % 10;
    printf("----------------------------------------\n");
    printf("Selamat datang di Wahana Mandi Bola!\n\n");
    printf("Silakan beli tiket terlebih dahulu untuk masuk ke wahana ini.\n\n");
    printf("Harga tiket:\n");
    printf("- Anak-anak (usia 0-12 tahun): Rp 10000\n");
    printf("- Dewasa (usia 13-64 tahun): Rp 20000\n");
    printf("- Lansia (usia 65 tahun ke atas): Rp 15000\n\n");
    printf("Jumlah anak: %d\n", ank2);
    printf("Jumlah dewasa: %d\n", dewasa);
    printf("Jumlah lansia: %d\n", lansia);

    PrintTiket(ank2, dewasa, lansia);
}   

void HandleNimonsHunting(long input)
{
    printf("----------------------------------------\n");
    printf("Selamat datang di Treasure Hunting Nimons!\n");
    printf("\n");
    printf("%ld", input);
    int jumlah_pergerakan, jumlah_lubang, jumlah_harta_karun, temp, sisa, harga;
    int ditemukan_lubang, ditemukan_harta_karun, langkah_dilakukan;
    int count_lubang, count_harta_karun, total_langkah;
    temp = input % 1000;
    jumlah_pergerakan = temp % 10;
    jumlah_lubang = temp / 10 % 10;
    jumlah_harta_karun = temp / 100;
    printf("Jumlah pergerakan Nimons di dalam kolam: %d\n", jumlah_pergerakan);
    printf("Jumlah lubang yang ada di kolam: %d\n", jumlah_lubang);
    printf("Jumlah harta karun yang ada di kolam: %d\n", jumlah_harta_karun);

    sisa = input / 1000;
    total_langkah = 0;
    count_harta_karun = 0;
    count_lubang = 0;
    for (int i = 1; i <= jumlah_pergerakan; i++)
    {   
        input /= 1000;
        sisa = input % 1000;
        ditemukan_lubang = sisa / 100;
        ditemukan_harta_karun = sisa/ 10 % 10;
        langkah_dilakukan = sisa % 10;
        printf("%d %d %d", ditemukan_lubang, ditemukan_harta_karun, langkah_dilakukan);
        printf("Langkah ke-%d\n",i);
        if (langkah_dilakukan == 0)
        {
            printf("Nimons tidak bergerak\n");
        }
        else
        {   total_langkah += langkah_dilakukan;
            printf("Nimons bergerak sejauh %d langkah\n", langkah_dilakukan);
            if (ditemukan_harta_karun >= 1)
            {
                printf("Nimons menemukan harta karun!\n");
                count_harta_karun++;
            }
            if (ditemukan_lubang >= 1)
            {
                printf("Nimons menutup lubang!\n");
                count_lubang++;
            }
        }
    }
    printf("\n");
    harga = input / 1000;
    printf("Total lubang yang ditutup: %d dari %d lubang\n", count_lubang, jumlah_lubang);
    printf("Total harta karun yang ditemukan: %d\n", count_harta_karun);
    printf("Total harga harta karun yang ditemukan: %d\n", count_harta_karun * harga * 5);
    printf("Total langkah yang ditempuh: %d\n", total_langkah);
    printf("Total biaya ganti rugi Pak Gro: %d\n", harga * count_lubang);
    printf("Total keuntungan Nimons dan Pak Gro: %d\n", (count_harta_karun * harga * 5) - (harga * count_lubang));
}

