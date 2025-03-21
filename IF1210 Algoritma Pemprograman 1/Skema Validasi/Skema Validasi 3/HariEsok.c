// PROGRAM HARI ESOK
// Input : integer a,b,c 
// Proses : Memasukannya ke dalam data type Tanggal kemudian mengunakan skema validasi 2 untuk mendapatkan nilai valid
// Output : Menampilkan ke layar dengan format hari(angka), bulan(kata), tahun(angka) untuk hari yang dimasukan dan hari esoknya

#include <stdio.h>
// KAMUS
typedef struct 
{
    int DD; // Hari
    int MM; // Bulan
    int YY; // Tahun

}Tanggal;


int kabisat(int tt);
/* Diberikan tahun akan mengeluarkan true jika tahun kabisat dan false jika tidak */

int IsTanggalValid(int hh,int bb, int tt);
/* Diberikan type Tanggal akan mengeluarkan true jika valid dan false jika tidak */

const char* NamaBulan(int bb);
/* Merubah bulan dalam angka menjadi bulan dalam kata standar bahasa Indonesia */

void Bacatanggal(Tanggal *Date);
/* Diberikan type data tanggal akan meminta user untuk mengisinya sampai mendapatkan tanggal yang valid */

Tanggal Nextday(Tanggal Date);
/* Diberikan type data tanggal akan meminta user untuk mengisinya sampai mendapatkan tanggal yang valid */

void TulisTanggal(Tanggal Date);
/*Meminta data type tunggal dan mencetak hari(dalam angka) bulan(dalam kata) tahun(dalam angka) */


// ALGORITMA UTAMA
int main(){
    Tanggal skrg ;
    Bacatanggal(&skrg);
    printf("Tanggal hari ini adalah: ");
    TulisTanggal(skrg);
    printf("Tanggal besok adalah: ");
    skrg = Nextday(skrg);
    TulisTanggal(skrg);
    return 0;
}

int kabisat(int tt){
    /*Diberikan tahun akan mengeluarkan true jika tahun kabisat dan false jika tidak. Kabisat ketika Secara matematis, 
      sebuah tahun dikatakan kabisat jika memenuhi salah satu dari dua kondisi berikut:
      yy mod 4 = 0 dan y mod 100 != 0
      yy mod 400 = 0 */ 
    
    // KAMUS LOKAL

    // ALGORITMA
    if (tt % 4 == 0){
        if (tt % 100 == 0){
            if (tt % 400 == 0){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            return 1;
        }
        return 0;
    }
    return 0;
}

int IsTanggalValid(int hh,int bb, int tt){
    /*Diberikan type Tanggal mengeluarkan true jika valid ketika 
      hari,bulan dan tahun harus positif dan tidak melebihi harinya 
      pada bulan tersebut dan tahun tersebut */
    
    // KAMUS LOKAL
    /* function Kabisat(yy : integer) -> boolean
        Diberikan tahun akan mengeluarkan true jika tahun kabisat dan false 
        jika tidak */

    // ALGORITMA
    if (hh > 0 && bb > 0 && tt > 0 && bb <= 12) { // cek bulan, tahun harus positif dan tidak melebihi harinya
        if (bb == 2){ // Kasus februari
            if (kabisat(tt) == 1){
                if (hh <= 29){ // tahun kabisat
                    return 1;
                }
                else{ // melebihi 29 hari
                    return 0;
                }
            }else{ // bukan tahun kabisat
                if (hh <= 28){
                    return 1;
                }else{ // melebuhi 28 hari
                    return 0;
                }
            }
        }else if (bb == 4 || bb == 6 || bb == 9 || bb == 11){ // Cek bulan yang ada 30 hari
            if(hh <= 30){
                return 1;
            }else{ // melebihi 30 hari
                return 0;
            }
        }else if (bb ==1 || bb ==3 || bb == 5 || bb == 7 || bb == 8 || bb == 10 || bb == 12){ // cek bulan yang ada 31 hari
            if (hh <= 31){
                return 1;
            }else{ // melebihi 30 hari
                return 0;
            }}
        else{return 0;}} // penanganan kasus kosong
    else{
        return 0;}} // bulan, tahun, hari, tidak positif atau melebihi 12 bulan

const char* NamaBulan(int bb) {
    /* Merubah bulan dalam angka menjadi bulan dalam kata standar bahasa Indonesia*/
    // KAMUS LOKAL
    // ALGORITMA
    if ( bb == 1){
        return "Januari";
    }
    if (bb == 2){
        return "Februari";
    }
    if (bb == 3){
        return "Maret";
    }
    if (bb == 4){
        return "April";
    }
    if (bb == 5){
        return "Mei";
    }
    if (bb == 6){
        return "Juni";
    }
    if (bb == 7){
        return "Juli";
    }
    if (bb == 8){
        return "Agustus";
    }
    if (bb == 9){
        return "September";
    }
    if (bb == 10){
        return "Oktober";
    }
    if(bb == 11){
        return "November";}
    if(bb == 12){
        return "Desember";}
    else{
        return "";}
}
void Bacatanggal(Tanggal *Date){
    /* Menggunakan skema validasi 2 untuk memastikan data yang dimasukan valid */
    // KAMUS LOKAL
    int hh,bb,tt;
    /* function IsTanggalValid(Date : Tanggal) -> boolean 
       Diberikan type Tanggal mengeluarkan true jika valid ketika hari */
    
    // ALGORITMA
    for(;;){
        printf("Masukkan tanggal: ");
        scanf("%d %d %d", &hh, &bb, &tt);
        if (IsTanggalValid(hh,bb,tt) == 1){
            break;
        }
        else{
            printf("Masukkan tanggal yang valid\n");
        }
    }
    (*Date).DD=hh;
    (*Date).MM =bb;
    Date->YY= tt;
}
Tanggal Nextday(Tanggal Date){
    // menerima data type Tanggal dan menghasilkan tanggal besok dari Tanggal
    
    // KAMUS LOKAL 
    // Kabisat(yy) -> boolean
    // Diberikan tahun mengoutput true jika tahun itu tahun kabisat 
    
    // ALGORITMA
    if (Date.MM == 2){
        if(Date.DD < 28){
            Date.DD += 1 ;
            return(Date);}
        else if(Date.DD == 28){
            if( kabisat(Date.YY) == 1){
                Date.DD += 1 ;
                return(Date) ;}
            else{
                Date.DD = 1; Date.MM += 1 ;
                return(Date) ;}}
        else if (Date.DD == 29){
            Date.DD = 1; Date.MM += 1;
            return(Date);}
        else{ 
            printf("Terjadi Kesalahan");}}
    else if (Date.MM == 12){
        if(Date.DD < 31){
            Date.DD += 1;
            return(Date);}
        else if (Date.DD == 31){
            Date.DD = 1; Date.MM =1, Date.YY += 1;
            return(Date);}
        else{ printf("Terjadi Kesalahan");}
    }
    else if ((Date.MM == 1) ||( Date.MM == 3)||(Date.MM == 5) || (Date.MM == 7) ||(Date.MM == 8)|| (Date.MM == 10) ){
            if (Date.DD < 31){
                Date.DD += 1;
                return Date;} 
            else{
                Date.DD = 1 ; Date.MM += 1;
                return Date;}}
    else if ( (Date.MM == 4) || (Date.MM == 6)|| (Date.MM == 9)|| (Date.MM == 11)){
                if (Date.DD < 30){
                    Date.DD += 1;
                    return Date;}
                else{
                    Date.DD = 1 ; Date.MM += 1;
                    return Date;}}
    else{printf("terjadi kesalahan");}
    
}
void TulisTanggal(Tanggal Date){
    // Menulis tanggal dalam format hari(angka), bulan(kata), tahun(angka)
    // KAMUS LOKAL
    // function NamaBulan(yy : int) -> string
    /* Merubah bulan dalam angka menjadi bulan dalam kata standar bahasa Indonesia*/
    printf("%d %s %d\n", Date.DD,NamaBulan(Date.MM), Date.YY );
}

