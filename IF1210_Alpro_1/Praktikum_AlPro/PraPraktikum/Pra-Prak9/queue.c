
/* Definisi ADT Queue versi 3 dengan representasi array secara eksplisit dan alokasi statik */

#include "queue.h"
#include "boolean.h"
#include <stdio.h>

/* *** Kreator *** */
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
void CreateQueue(Queue *q)
{
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isEmpty(Queue q)
{
    return IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF;
}

/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
boolean isFull(Queue q)
{
    return (IDX_TAIL(q) + 1) % CAPACITY == IDX_HEAD(q);
}

/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
int length(Queue q)
{
    if (isEmpty(q)) return 0;
    if (IDX_TAIL(q) >= IDX_HEAD(q)) {
        return IDX_TAIL(q) - IDX_HEAD(q) + 1;
    }
    else return CAPACITY + (IDX_TAIL(q) - IDX_HEAD(q)) + 1;
}

/* *** Primitif Add/Delete *** */
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q mungkin penuh. Jangan lakukan apapun apabila penampung penuh. */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
void enqueue(Queue *q, ElType val)
{
    if ((!isFull(*q))) {
        if (isEmpty(*q)) {
            IDX_HEAD(*q) = 0;
            IDX_TAIL(*q) = 0;
        }
        else {
            IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
        }
        TAIL(*q) = val;
    }
}

/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, jangan lakukan apa-apa bila kosong*/
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */
void dequeue(Queue *q, ElType *val)
{
    if (!isEmpty(*q)) {
        *val = HEAD(*q);
        if (IDX_HEAD(*q) == IDX_TAIL(*q)) {
            IDX_HEAD(*q) = IDX_UNDEF;
            IDX_TAIL(*q) = IDX_UNDEF;
        }
        else {
            IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
        }
    }
}

/* *** Display Queue *** */
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang setiap elemen queue, termasuk spasi dan enter */
/* Tambahkan \n ketika Queue sudah selesai di tulis */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
void displayQueue(Queue q)
{
    printf("[");
    if (!isEmpty(q)) {
        int i = IDX_HEAD(q);
        while (1) {
            printf("%d", q.buffer[i]);
            if (i == IDX_TAIL(q)) break;
            printf(",");
            i = (i + 1) % CAPACITY;
        }
    }

    printf("]\n");
}

