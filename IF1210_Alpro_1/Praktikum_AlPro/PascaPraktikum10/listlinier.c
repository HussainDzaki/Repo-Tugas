/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* ElType adalah integer */

#include "listlinier.h"
#include "Boolean.h"
#include <stdio.h>
#include <stdlib.h>

/* Definisi Node : */

#define INFO(p) (p)->info
#define NEXT(p) (p)->next

/* Definisi List : */

/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */
Address newNode(ElType val)
{
    Address new = (Address)malloc(sizeof(Node));
    if (new != NULL) {
        INFO(new) = val;
        NEXT(new) = NULL;
    }
    return new;
}

typedef Address List;

#define IDX_UNDEF (-1)
#define FIRST(l) (l)

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/

/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
void CreateList(List *l)
{
    *l = NULL;
}

/****************** TEST LIST KOSONG ******************/

/* Mengirim true jika list kosong */
boolean isEmpty(List l)
{
    return l == NULL;
}

/****************** GETTER SETTER ******************/

/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
ElType getElmt(List l, int idx)
{
    if (isEmpty(l)) {
        return -1;
    }
    else {
        Address p = l;
        int cnt = 0;
        while (p != NULL && cnt != idx) {
            cnt++;
            p = p->next;
        }
        return INFO(p);
    }
}

/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
void setElmt(List *l, int idx, ElType val)
{
    Address p = *l;
    int i = 0;
    while (i < idx && p != NULL) {
        p = p->next;
        i++;
    }
    if (p != NULL) {
        p->info = val;
    }
}

/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
int indexOf(List l, ElType val)
{
    int idx = 0;
    while (l != NULL) {
        if (INFO(l) == val) return idx;
        l = l->next;
        idx++;
    }
    return IDX_UNDEF;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/

/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
void insertFirst(List *l, ElType val)
{
    Address p;
    p = newNode(val);
    if (p != NULL) {
        NEXT(p) = *l;
        *l = p;
    }
}

/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
void insertLast(List *l, ElType val)
{
    if (isEmpty(*l)) {
        insertFirst(l, val);
    }
    else {
        Address p = newNode(val);
        Address last = *l;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = p;
    }
}

/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
void insertAt(List *l, ElType val, int idx)
{
    if (idx == 0) {
        insertFirst(l, val);
    }
    else {
        Address p = newNode(val);
        Address atIdx = *l;
        int i = 0;
        while (i < idx - 1 && atIdx != NULL) {
            i++;
            atIdx = atIdx->next;
        }
        NEXT(p) = NEXT(atIdx);
        NEXT(atIdx) = p;
    }
}



/*** PENGHAPUSAN ELEMEN ***/

/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteFirst(List *l, ElType *val)
{
    Address p = *l;
    *val = p->info;
    *l = p->next;
    free(p);
}

/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
void deleteLast(List *l, ElType *val)
{
    Address last = *l;
    Address prev = NULL;
    if ((*l)->next == NULL) {
        *val = (*l)->info;
        free(*l);
        *l = NULL;
    }
    else {
        Address prev = NULL, last = *l;
        while (last->next != NULL) {
            prev = last;
            last = last->next;
        }
        *val = last->info;
        free(last);
        prev->next = NULL;
    }
}

/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
void deleteAt(List *l, int idx, ElType *val)
{
    int ctr = 0;
    Address p, loc;
    if (idx == 0) {
        deleteFirst(l, val);
    }
    else {
        loc = *l;
        while (ctr < (idx - 1)) {
            ctr++;
            loc = loc->next;
        }
        p = loc->next;
        *val = p->info;
        loc->next = p->next;
        free(p);
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/

// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void displayList(List l)
{
    printf("[");
    Node *p = l;
    int len = length(l);
    int cnt = 0;
    while (p != NULL) {
        printf("%d", p->info);
        if (cnt < len - 1) {
            printf(",");
        }
        cnt++;
        p = p->next;
    }
    printf("]");
}

/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
int length(List l)
{
    Address p = l;
    int cnt = 0;
    while (p != NULL) {
        cnt++;
        p = p->next;
    }
    return cnt;
}

/****************** PROSES TERHADAP LIST ******************/

/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */
List concat(List l1, List l2)
{
    List l3;
    CreateList(&l3);
    Address p1 = l1;
    Address p2 = l2;

    while (p1 != NULL) {
        insertLast(&l3, p1->info);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insertLast(&l3, p2->info);
        p2 = p2->next;
    }
    return l3;
}

