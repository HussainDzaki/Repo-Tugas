/* Program POKOKPERSOALAN */
/* Spesifikasi: 
   - Input: Tanggal yang dimasukkan oleh pengguna (hari, bulan, tahun).
   - Proses: Memeriksa validitas tanggal, menentukan tahun kabisat, dan menghitung tanggal berikutnya.
   - Output: Menampilkan tanggal yang dimasukkan dan tanggal berikutnya.
*/
/* Prototype Fungsi */
typedef struct 
{
    int DD;
    int MM;
    int YY;

}Tanggal;
int kabisat(int tt); // Fungsi untuk menentukan apakah suatu tahun adalah tahun kabisat
int IsTanggalValid(int hh, int bb, int tt); // Fungsi untuk memeriksa validitas tanggal
const char* NamaBulan(int bb); // Fungsi untuk mengembalikan nama bulan berdasarkan nomor bulan
void Bacatanggal(Tanggal *Date); // Fungsi untuk membaca tanggal dari pengguna
Tanggal Nextday(Tanggal Date); // Fungsi untuk menghitung tanggal berikutnya
void TulisTanggal(Tanggal Date); // Fungsi untuk menulis tanggal ke layar

int main () {
    /* KAMUS */
    Tanggal skrg; // Variabel untuk menyimpan tanggal yang dimasukkan oleh pengguna

    /* ALGORITMA */
    Bacatanggal(&skrg); // Memanggil fungsi untuk membaca tanggal dari pengguna
    TulisTanggal(skrg); // Menampilkan tanggal yang dimasukkan
    skrg = Nextday(skrg); // Menghitung tanggal berikutnya
    TulisTanggal(skrg); // Menampilkan tanggal berikutnya

    return 0;
}

/* Body/Realisasi Fungsi diletakkan setelah program utama */

/* Fungsi untuk menentukan apakah suatu tahun adalah tahun kabisat */
int kabisat(int tt) {
    if (tt % 4 == 0) {
        if (tt % 100 == 0) {
            if (tt % 400 == 0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    }
    return 0;
}

/* Fungsi untuk memeriksa validitas tanggal */
int IsTanggalValid(int hh, int bb, int tt) {
    if (hh > 0 && bb > 0 && tt > 0 && bb <= 12) {
        if (bb == 2) {
            if (kabisat(tt) == 1) {
                if (hh <= 29) {
                    return 1;
                } else {
                    return 0;
                }
            } else {
                if (hh <= 28) {
                    return 1;
                } else {
                    return 0;
                }
            }
        } else if (bb == 4 || bb == 6 || bb == 9 || bb == 11) {
            if (hh <= 30) {
                return 1;
            } else {
                return 0;
            }
        } else if (bb == 1 || bb == 3 || bb == 5 || bb == 7 || bb == 8 || bb == 10 || bb == 12) {
            if (hh <= 31) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

/* Fungsi untuk mengembalikan nama bulan berdasarkan nomor bulan */
const char* NamaBulan(int bb) {
    if (bb == 1) return "Januari";
    if (bb == 2) return "Februari";
    if (bb == 3) return "Maret";
    if (bb == 4) return "April";
    if (bb == 5) return "Mei";
    if (bb == 6) return "Juni";
    if (bb == 7) return "Juli";
    if (bb == 8) return "Agustus";
    if (bb == 9) return "September";
    if (bb == 10) return "Oktober";
    if (bb == 11) return "November";
    if (bb == 12) return "Desember";
    return "";
}

/* Fungsi untuk membaca tanggal dari pengguna */
void Bacatanggal(Tanggal *Date) {
    int hh, bb, tt;
    for (;;) {
        printf("Masukkan tanggal: ");
        scanf("%d %d %d", &hh, &bb, &tt);
        if (IsTanggalValid(hh, bb, tt) == 1) {
            break;
        } else {
            printf("Masukkan tanggal yang valid\n");
            while (getchar() != '\n');
            printf("Tolong masukkan tanggal bukan kata\n");
        }
    }
    Date->DD = hh;
    Date->MM = bb;
    Date->YY = tt;
}

/* Fungsi untuk menghitung tanggal berikutnya */
Tanggal Nextday(Tanggal Date) {
    if (Date.MM == 2) {
        if (Date.DD < 28) {
            Date.DD += 1;
            return Date;
        } else if (Date.DD == 28) {
            if (kabisat(Date.YY) == 1) {
                Date.DD += 1;
                return Date;
            } else {
                Date.DD = 1; Date.MM += 1;
                return Date;
            }
        } else if (Date.DD == 29) {
            Date.DD = 1; Date.MM += 1;
            return Date;
        } else {
            printf("Terjadi Kesalahan");
        }
    } else if (Date.MM == 12) {
        if (Date.DD < 31) {
            Date.DD += 1;
            return Date;
        } else if (Date.DD == 31) {
            Date.DD = 1; Date.MM = 1; Date.YY += 1;
            return Date;
        } else {
            printf("Terjadi Kesalahan");
        }
    } else if ((Date.MM == 1) || (Date.MM == 3) || (Date.MM == 5) || (Date.MM == 7) || (Date.MM == 8) || (Date.MM == 10)) {
        if (Date.DD < 31) {
            Date.DD += 1;
            return Date;
        } else {
            Date.DD = 1; Date.MM += 1;
            return Date;
        }
    } else if ((Date.MM == 4) || (Date.MM == 6) || (Date.MM == 9) || (Date.MM == 11)) {
        if (Date.DD < 30) {
            Date.DD += 1;
            return Date;
        } else {
            Date.DD = 1; Date.MM += 1;
            return Date;
        }
    } else {
        printf("terjadi kesalahan");
    }
}

/* Fungsi untuk menulis tanggal ke layar */
void TulisTanggal(Tanggal Date) {
    printf("%d %s %d\n", Date.DD, NamaBulan(Date.MM), Date.YY);
}