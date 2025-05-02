/* MODUL LIST INTEGER STATIK DENGAN ELEMEN POSITIF */
/* Berisi definisi dan semua primitif pemrosesan list integer statik dengan elemen positif */
/* Penempatan elemen selalu rapat kiri */
/* Banyaknya elemen didefinisikan secara implisit, memori list statik */

#ifndef LISTSTATIK_H
#define LISTSTATIK_H


#include "Boolean.h"
#include "stdio.h"

/*  Kamus Umum */
#define CAPACITY 100
/* Kapasitas penyimpanan */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
#define MARK -9999
/* Nilai elemen tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int ElType; /* type elemen List */
typedef int IdxType;
typedef struct
{
    ElType contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
} ListStatik;
/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika l adalah ListStatik, cara deklarasi dan akses: */
/* Deklarasi : l : ListStatik */
/* Maka cara akses:
   ELMT(l,i) untuk mengakses elemen ke-i */
/* Definisi :
   List kosong: semua elemen bernilai MARK
   Definisi elemen pertama: ELMT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define ELMT(l, i) (l).contents[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l){
    for (int i = 0; i < CAPACITY; i++){
        ELMT(*l, i) = MARK;
    }
}
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListStatik l){
    int n = 0;
    while (n < CAPACITY && ELMT(l, n) != MARK){
        n++;
    }
    return n;
}
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l){
    return 0;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdx(ListStatik l){
    return listLength(l) - 1;
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i){
    return 0 <= i && i < CAPACITY;
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ListStatik l, IdxType i){
    return 0 <= i && i <= listLength(l) - 1;
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l){
    return listLength(l) == 0;
}
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */

boolean isFull(ListStatik l){
    return listLength(l) == CAPACITY; 
    
}
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */

/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali:
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
void readList(ListStatik *l)
{
    CreateListStatik(l);
    int n;
    do{
        scanf("%d", &n);
    } while (!(0 <= n && n <= CAPACITY));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ELMT(*l,i));
    }
}

/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
void printList(ListStatik l)
{
    printf("[");
    for (int i = 0; i < listLength(l); i++){
        printf("%d", ELMT(l, i));
        if (i < listLength(l) - 1){
            printf(",");
        }
    }
    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */

/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi
       elemen l2 pada indeks yang sama */
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus){
    ListStatik l3;
    CreateListStatik(&l3);
    int len = listLength(l1);
    if (plus){
        for (int i = 0; i < len; i++){
            ELMT(l3, i) = ELMT(l1, i) + ELMT(l2, i);
        }
    }
    else{
        for (int i = 0; i < len; i++){
            ELMT(l3, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    
    return l3;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua
   elemennya sama */
boolean isListEqual(ListStatik l1, ListStatik l2){
    int same = 1;
    if (listLength(l1) == listLength(l2)){
        int ln = listLength(l1);
        for (int i = 0; i < ln && same; i++){
            if (ELMT(l1,i) != ELMT(l2,i)){
                same = 0;
            }
        }
        return same;
    }
    return !same;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */

/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */
int indexOf(ListStatik l, ElType val){
    if (isEmpty(l)){
        return IDX_UNDEF;
    }
    else{
        int i = 0;
        while (ELMT(l, i) != val && ELMT(l, i) != MARK && i < listLength(l)-1){
            i++;
        }
        if (ELMT(l, i) == val){
            return i;
        }
        else{
            return IDX_UNDEF;
        }
    }
}

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, ElType *max, ElType *min){
    ElType max1 = ELMT(l, 0);
    ElType min1 = ELMT(l, 0);
    int ln = listLength(l);
    for (int i = 0; i < ln; i++){
        if (ELMT(l, i) > max1){
            max1 = ELMT(l, i);
        }
        if (ELMT(l, i) < min1){
            min1 = ELMT(l, i);
        }
    }
    *max = max1;
    *min = min1;
}
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */



/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
void insertAt(ListStatik *l, ElType val, IdxType idx){
    int ln = listLength(*l);
    for (int i = ln; i > idx; i--){
        ELMT(*l, i) = ELMT(*l, i - 1);
    }
    ELMT(*l, idx) = val;
}

/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
void insertFirst(ListStatik *l, ElType val){
    insertAt(l,val,0);
}


void insertLast(ListStatik *l, ElType val){
    ELMT(*l, listLength(*l)) = val;
}
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */

void deleteFirst(ListStatik *l, ElType *val){
    *val = ELMT(*l, 0);
    int len = listLength(*l) - 1;
    for (int i = 0; i < len; i++){
        ELMT(*l, i) = ELMT(*l, i + 1);
    }
    ELMT(*l, listLength(*l) - 1) = MARK;
}
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen pada index tertentu *** */



void deleteAt(ListStatik *l, ElType *val, IdxType idx){
    *val = ELMT(*l,idx);
    int ln = listLength(*l);
    for (int i = idx; i < ln - 1; i++){
        ELMT(*l, i) = ELMT(*l, i + 1);
    }
    ELMT(*l, listLength(*l) - 1) = MARK;
}
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen terakhir *** */
void deleteLast(ListStatik *l, ElType *val){
    *val = ELMT(*l, getLastIdx(*l));
    ELMT(*l, getLastIdx(*l)) = MARK;
}
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********** SORTING ********** */
void sortList(ListStatik *l, boolean asc){
    if (!isEmpty(*l)){
        if (asc){
            for (int pass = 1; pass < listLength(*l); pass++){
                int j = pass - 1;
                ElType key = ELMT(*l, pass);
                while (j >= 0 && key < ELMT(*l, j)){
                    ELMT(*l, j + 1) = ELMT(*l, j);
                    j--;
                }
                ELMT(*l, j + 1) = key;
            }
        }
        else{
            for (int pass = 1; pass < listLength(*l); pass++){
                int j = pass - 1;
                ElType key = ELMT(*l, pass);
                while (j >= 0 && key > ELMT(*l, j)){
                    ELMT(*l, j + 1) = ELMT(*l, j);
                    j--;
                }
                ELMT(*l, j + 1) = key;
            }
        }
    }
}

/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */



int isPalindrom(ListStatik l){
    int rg = getLastIdx(l);
    int lf = 0;
    int palindrom = 1;
    while (palindrom && ELMT(l,lf) != MARK && ELMT(l,rg) != MARK){
        if (ELMT(l,lf) != ELMT(l,rg)){
            palindrom = 0;
        }
        rg--;
        lf++;
    }
    return palindrom;
}

void closestPair(ListStatik l, ElType *p1, ElType *p2){
    *p1 = ELMT(l,0);
    *p2 = ELMT(l,1);
    int len = listLength(l);
    ElType minsubs = (*p1 - *p2) > 0 ? *p1 - *p2 : *p2 - *p1;
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len; j++){
            ElType min = (ELMT(l,i) - ELMT(l,j) > 0) ? ELMT(l,i) - ELMT(l,j) : ELMT(l,j) - ELMT(l,i);
            if (i != j){
                if (minsubs > min){
                    minsubs = min;
                    *p1 = ELMT(l,i);
                    *p2 = ELMT(l,j);
                }
          }
        }
    }    
}


int isFront(ListStatik l1 , ListStatik l2){
    if (isEmpty(l1) ){
        return 1;
    }else{
        if (listLength(l1) < listLength(l2)){
            int len = listLength(l1);
            for (int i = 0; i < len && ELMT(l1,i) != MARK && ELMT(l2,i) != MARK; i++){
                if (ELMT(l1,i) != ELMT(l2,i)){
                    return 0;
                }
            }
            return 1;
            
        }else{
            return 0;
        }
        
    }
    
}



#endif