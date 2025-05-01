/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#ifndef LISTDIN_H
#define LISTDIN_H

#include "Boolean.h"
#include <stdio.h>
#include <stdlib.h>

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int ElType; /* type elemen list */
typedef int IdxType;
typedef struct
{
    ElType *buffer; /* memori tempat penyimpan elemen (container) */
    int nEff;       /* >=0, banyaknya elemen efektif */
    int capacity;   /* ukuran elemen */
} ListDin;
/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah : ListDin, cara deklarasi dan akses: */
/* Deklarasi : l : ListDin */
/* Maka cara akses:
   l.nEff      untuk mengetahui banyaknya elemen
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  list kosong: l.nEff = 0
  Definisi elemen pertama : l.buffer[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.capacity */

/* ********** SELEKTOR ********** */
#define NEFF(l) (l).nEff
#define BUFFER(l) (l).buffer
#define ELMT(l, i) (l).buffer[i]
#define CAPACITY(l) (l).capacity

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
void CreateListDin(ListDin *l, int capacity){
    BUFFER(*l) = (ElType*) malloc(capacity*sizeof(ElType));
    NEFF(*l) = 0;
    CAPACITY(*l) = capacity;
}

/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
void dealocateList(ListDin *l){
    free(BUFFER(*l));
    NEFF(*l) = 0;
    CAPACITY(*l) = 0;
}


/* ********** SELEKTOR (TAMBAHAN) ********** */

/* *** Banyaknya elemen *** */
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
int listLength(ListDin l){
    return NEFF(l);
}


/* *** Selektor INDEKS *** */
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getFirstIdx(ListDin l){
    return 0;
}

/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
IdxType getLastIdx(ListDin l){
    return listLength(l) - 1;
}


/* ********** Test Indeks yang valid ********** */

/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxValid(ListDin l, IdxType i){
    return i >= IDX_MIN && i < l.capacity;
}

/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
boolean isIdxEff(ListDin l, IdxType i){
    return i >= IDX_MIN && i <= NEFF(l);
}


/* ********** TEST KOSONG/PENUH ********** */

/* *** Test list kosong *** */
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isEmpty(ListDin l){
   return listLength(l) == 0;
    
}

/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
boolean isFull(ListDin l){
    return CAPACITY(l) == listLength(l);
}


/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */


/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void readList(ListDin *l){
    int caps;
    do{
        scanf("%d", &caps );
    } while (!(0 <= caps && caps <= CAPACITY(*l)));

    for (int i = 0; i < caps; i++){
        scanf("%d", &ELMT(*l,i));
    }
    NEFF(*l) = caps;
    
    
}

/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
void printList(ListDin l){
    printf("[");
    int ln = listLength(l);
    for (int i = 0; i < ln; i++){
        printf("%d", ELMT(l,i));
        if(i < ln - 1){
            printf(",");
        }
    }
    printf("]");
    
}


/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */

/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
    ListDin l3;
    int maxlen = NEFF(l1) > NEFF(l2) ? NEFF(l1) : NEFF(l2);
    int minlen = NEFF(l1) < NEFF(l2) ? NEFF(l1) : NEFF(l2);
    CreateListDin(&l3, maxlen);
    CAPACITY(l3) = maxlen;
    
    if (plus){
        for (int i = 0; i < maxlen; i++){
            ELMT(l3,i) = ELMT(l1,i) + ELMT(l2,i);
        }
    }
    else{
        for (int i = 0; i < maxlen; i++){
            ELMT(l3,i) = ELMT(l1,i) - ELMT(l2,i);
        }
    }
    NEFF(l3) = maxlen;
    return l3;
}


/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */

/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
boolean isListEqual(ListDin l1, ListDin l2){
    if (NEFF(l1) == NEFF(l2)){
        int len = listLength(l1);
        int sama = 1;
        for (int i = 0; i < len && sama ; i++){
            if (ELMT(l1,i) != ELMT(l2,i)){
                sama = 0;
            }
        }
        return sama;
    }
    return 0;
    
}


/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */

/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
IdxType indexOf(ListDin l, ElType val){
    if (!isEmpty(l)){
        int len = listLength(l);
        for (int i = 0; i < len ; i++){
            if (ELMT(l,i) == val){
                return i;
            }
        }
        return IDX_UNDEF;
        
    }
    return IDX_UNDEF;
    
}


/* ********** NILAI EKSTREM ********** */

/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
void extremeValues(ListDin l, ElType *max, ElType *min){
    int len = listLength(l);
    *max = ELMT(l,0);
    *min = ELMT(l,0);
    for (int i = 1; i < len; i++){
        if(*max < ELMT(l,i)){
            *max = ELMT(l,i);
        }
        if(*min > ELMT(l,i)){
            *min = ELMT(l,i);
        }
    }
}


/* ********** OPERASI LAIN ********** */

/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
void copyList(ListDin lIn, ListDin *lOut){
    CreateListDin(lOut, CAPACITY(lIn));
    int len = NEFF(lIn);
    for (int i = 0; i < len; i++){
        ELMT(*lOut,i) = ELMT(lIn,i);
    }
    NEFF(*lOut) = len; 
    
}

/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
ElType sumList(ListDin l){
    ElType sum = 0;
    for (int i = 0; i < listLength(l); i++){
        sum += ELMT(l, i);
    }
    return sum;
    
}

/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
int countVal(ListDin l, ElType val){
    int cnt = 0;
    for (int i = 0; i < listLength(l); i++){
        if (ELMT(l,i) == val){
            cnt ++;
        }
    }
    return cnt;
}


/* ********** SORTING ********** */
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
void sort(ListDin *l, boolean asc){
    if (!isEmpty(*l)){   
        if (asc){
            int len = listLength(*l);
            ElType temp;
            int j;
            for (int i = 1; i < len; i++){
                j = i -1;
                temp = ELMT(*l,i);
                while (j >= 0 && temp < ELMT(*l,j)){
                    ELMT(*l,j +1) = ELMT(*l, j);
                    j --;
                }
                ELMT(*l, j + 1) = temp;
            }
          }else{
            int len = listLength(*l);
            ElType temp;
            int j;
            for (int i = 1; i < len; i++){
                j = i -1;
                temp = ELMT(*l,i);
                while (j >= 0 && temp > ELMT(*l,j)){
                    ELMT(*l,j +1) = ELMT(*l, j);
                    j --;
                }
                ELMT(*l, j + 1) = temp;
            }
        }
    }
    
}


/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */


/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
void insertLast(ListDin *l, ElType val){
    ELMT(*l, listLength(*l)) = val;
    NEFF(*l) += 1;
    
}


/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val){
    *val = ELMT(*l, getLastIdx(*l));
    NEFF(*l) -= 1;
}


/* ********* MENGUBAH UKURAN ARRAY ********* */

/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
void expandList(ListDin *l, int num){
    BUFFER(*l) = (ElType*) realloc(BUFFER(*l), (CAPACITY(*l) + num) * sizeof(ElType));
    CAPACITY(*l) += num;
}


/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
void shrinkList(ListDin *l, int num){
    BUFFER(*l) = (ElType*) realloc(BUFFER(*l), (CAPACITY(*l) - num) * sizeof(ElType));
    CAPACITY(*l) -= num;
}

/* Proses : Mengubah capacity sehingga nEff = capacity */
/* I.S. List tidak kosong */
/* F.S. Ukuran nEff = capacity */
void compressList(ListDin *l){
    BUFFER(*l) = (ElType*) realloc(BUFFER(*l), (NEFF(*l)) * sizeof(ElType));
    CAPACITY(*l) = NEFF(*l);
}
#endif
