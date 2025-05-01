/**
 * Pengolahan Data para Nimons
 *
 * INPUT
 * sebuah nama file untuk dibaca.
 *
 * FORMAT FILE MASUKAN: (Asumsikan format input sudah pasti valid)
 *
 * NIM1|Nama1|Nilai1,Nilai2,Nilai3,...
 * NIM2|Nama2|Nilai1,Nilai2,Nilai3,...
 * ...
 * NIMN|NamaN|Nilai1,Nilai2,Nilai3,...
 *
 * NOTE:
 * - Panjang karakter NIM maksimal 20
 * - Panjang karakter Nama maksimal 100
 * - Panjang karakter Nilai maksimal 20
 * - Nilai dalam format integer
 *
 *
 * OUTPUT
 *
 * FORMAT KELUARAN PADA CONSOLE:
 *
 * NIM1|Nama1|Rata-rata|Tertinggi|Terendah|Status(newline)
 * NIM2|Nama2|Rata-rata|Tertinggi|Terendah|Status(newline)
 * ...(newline)
 * NIMN|NamaN|Rata-rata|Tertinggi|Terendah|Status(newline)
 * TotalNimons(newline)
 * JumlahLulus PesentaseLulus(newline)
 * JumlahTidakLulus PesentaseTidakLulus(newline)
 * NIMTertinggi|NamaTertinggi|Rata-rataTertinggi(newline)
 *
 * NOTE:
 * - Rata-rata ditulis dengan 2 angka di belakang koma
 * - Status dalam format "PASS" atau "FAIL"
 * - Persentase lulus dan tidak lulus ditulis dengan 2 angka di belakang koma
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IO_LENGTH 100    // Panjang maksimal nama file input/output
#define MAX_NAME_LENGTH 100  // Panjang maksimal nama
#define MAX_NIM_LENGTH 20    // Panjang maksimal NIM
#define MAX_LINE_LENGTH 1024 // Panjang maksimal satu baris
#define MAX_SCORES 20        // Maksimal jumlah nilai per nimon
#define MAX_NIMONS 100       // Maksimal jumlah nimons
#define PASS_THRESHOLD 60    // Ambang batas kelulusan (harus >= 60)

// Struktur data untuk menyimpan data nilai nimons dan juga beberapa statistiknya
typedef struct
{
    char nim[MAX_NIM_LENGTH];
    char name[MAX_NAME_LENGTH];
    int scores[MAX_SCORES];
    int scoreCount;
    float average;
    int highest;
    int lowest;
    char status[5]; // "PASS" or "FAIL"
} Nimon;

/**
 * Prosedur pembantu untuk melakukan parsing data nimons dari sebuah baris pada file input dalam format:
 *
 * NIM|Nama|Nilai1,Nilai2,Nilai3,...
 *
 * dan menyimpannya ke dalam struktur data Nimon.
 *
 * Hint:
 * 1. strtok - Memisahkan string berdasarkan delimiter
 *    Contoh:
 *    char str[] = "apple,banana,orange";
 *    char *token = strtok(str, ",");     // token = "apple"
 *    token = strtok(NULL, ",");          // token = "banana"
 *    token = strtok(NULL, ",");          // token = "orange"
 *
 *    Catatan: strtok mengubah string asli dengan menempatkan '\0'
 *    di tempat delimiter dan menyimpan posisi internal untuk
 *    pemanggilan berikutnya.
 *
 * 2. strcpy - Menyalin string dari sumber ke tujuan
 *    Contoh:
 *    char dest[20];
 *    char src[] = "Hello";
 *    strcpy(dest, src);  // dest sekarang berisi "Hello"
 *
 *    Catatan: Pastikan buffer tujuan cukup besar untuk
 *    menampung string sumber, termasuk null terminator.
 *
 * 3. atoi - Mengkonversi string menjadi nilai integer
 *    Contoh:
 *    char *num = "42";
 *    int value = atoi(num);  // value = 42
 *
 *    Catatan: atoi mengembalikan 0 jika konversi gagal.
 *
 * @line: baris yang berisi data nimons
 * @nimon: pointer ke struktur Nimon untuk menyimpan hasil parsing
 */
void parseStudentData(char *line, Nimon *nimon)
{

    strcpy(nimon->nim, strtok(line, "|"));
    strcpy(nimon->name, strtok(NULL, "|"));
    char semuanilai = strtok(NULL, "|");
    
}

/**
 * Prosedur pembantu untuk menghitung statistik dari sebuah nimon
 * - Rata-rata
 * - Nilai tertinggi
 * - Nilai terendah
 * - Status (PASS/FAIL)
 *
 * @nimons: pointer ke struktur Nimon yang berisi data nimons
 */
void calculateStatistics(Nimon *nimon)
{
    int sums = 0, cnt = 0, min = 1000, max = -999, cur;
    char *nilai = strtok(nimon->scores, ",");

    while (nilai != NULL)
    {
        cur = atoi(strtok(NULL, ","));
        if (cur < min)
        {
            min = cur;
        }
        if (cur > max)
        {
            max = cur;
        }

        sums += cur;
        cnt++;
    }
    nimon->average = (float)sums / cnt;
    nimon->highest = max;
    nimon->lowest = min;
    if (nimon->average >= PASS_THRESHOLD)
    {
        strcpy(nimon->status, "PASS");
    }
    else
    {
        strcpy(nimon->status, "FAIL");
    }
}

/**
 * Prosedur pembantu untuk menulis hasil nimons ke console dengan format:
 *
 * NIM|Nama|Rata-rata|Tertinggi|Terendah|Status(newline)
 *
 * NOTE:
 * - Rata rata ditulis dengan 2 angka di belakang koma
 * - status dalam format "PASS" atau "FAIL"
 * - Jangan lupa menambahkan newline di akhir setiap baris
 *
 * @nimon: pointer ke struktur Nimon yang berisi data nimons
 *
 */
void writeStudentResult(Nimon *nimon)
{
    printf("%s|%s|%.2f|%d|%d|%s\n", nimon->nim, nimon->name, nimon->average, nimon->highest, nimon->lowest, nimon->status);
}

/**
 * Prosedur pembantu untuk menghitung dan menulis ringkasan statistik kelas dalam format:
 *
 * TotalNimons(newline)
 * JumlahLulus PesentaseLulus(newline)
 * JumlahTidakLulus PesentaseTidakLulus(newline)
 * NIMTertinggi|NamaTertinggi|RataRataTertinggi(newline)
 *
 * NOTE:
 * - Persentase lulus dan tidak lulus ditulis dengan 2 angka di belakang koma
 * - Rata-rata tertinggi ditulis dengan 2 angka di belakang koma
 *
 * @nimons: array of Nimon structures
 * @nimonCount: jumlah nimons dalam array
 */
void writeSummary(Nimon *nimons, int nimonCount)
{
    int JumlahLulus, JumlahTidakLulus, i;
    Nimon key;

    for (int pass = 1; pass < nimonCount; pass++)
    {
        key = nimons[pass];
        i = pass - 1;
        while (i > 0 && (atoi(key.nim) < atoi(nimons[i].nim) && key.average < nimons[i].average))
        {
            nimons[i + 1] = nimons[i];
            i--;
        }
        nimons[i + 1] = key;
    }

    for (int i = 0; i < nimonCount; i++)
    {
        if (nimons[i].status == "PASS")
        {
            JumlahLulus++;
        }
        else
        {
            JumlahTidakLulus++;
        }
    }

    printf("%d\n", nimonCount);
    printf("%d %0.2f\n", JumlahLulus, (float)JumlahLulus / nimonCount);
    printf("%d %0.2f\n", JumlahTidakLulus, (float)JumlahTidakLulus / nimonCount);
    writeStudentResult(&nimons[0]);
}

/**
 * Fungsi utama akan membaca file input, memproses data nimons,
 * dan menampilkan hasilnya langsung ke console.
 *
 * NOTE: Gunakan fungsi-fungsi sebelumnya untuk mempermudah pengerjaan
 *
 * @inputFileName: nama file input
 * @return 0 jika berhasil, 1 jika gagal (misalnya file tidak ditemukan)
 */
int run(char *inputFileName)
{
    FILE *filenimons = fopen(inputFileName, "r");
    if (filenimons == NULL)
    {
        return 1;
    }
    char strNimon[MAX_IO_LENGTH];
    char readNimon[MAX_IO_LENGTH];
    strcpy(readNimon, fscanf(filenimons, "%s", &strNimon));

    Nimon nimons[MAX_NIMONS];
    int nimonsindex = 0;
    while (readNimon == 1 && readNimon != NULL)
    {
        parseStudentData(readNimon, &nimons[nimonsindex]);
        calculateStatistics(&nimons[nimonsindex]);
        strcpy(readNimon, fscanf(filenimons, "%s", &strNimon));
        nimonsindex++;
    }

    for (int j = 0; j < nimonsindex; j++)
    {
        writeStudentResult(&nimons[j]);
    }

    writeSummary(nimons, nimonsindex + 1);

    fclose(filenimons);
}
