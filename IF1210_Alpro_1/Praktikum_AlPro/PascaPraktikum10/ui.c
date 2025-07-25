#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

void dealokasiList(List *l)
{
    Address p_current = FIRST(*l); // Dapatkan pointer ke elemen pertama
    Address p_next;

    while (p_current != NULL) {
        p_next = NEXT(p_current); // Simpan pointer ke elemen berikutnya
        free(p_current);          // Bebaskan memori elemen saat ini
        p_current = p_next;       // Pindah ke elemen berikutnya
    }

    *l = NULL; // Setelah semua node dibebaskan, set pointer list utama ke NULL
}

void insertSorted(List *l, ElType val)
{
    Address p_current = *l;
    Address p_next = *l;
    Address p_new = newNode(val);

    if (*l == NULL || val < p_current->info) {
        p_new->next = p_current->next;
        *l = p_new;
    }
    else {
        while (p_current != NULL && p_current->info < val) {
            p_current = p_current->next;
        }
        p_new->next = p_current->next;
        p_current->next = p_new;
    }
}

/**
 * @brief Mengeluarkan hasil union dari 2 buah list
 * @param l1 adalah list pertama.
 * @param l2 adalah list kedua.
 * I.S. l1 dan l2 terdefinisi, mungkin kosong.
 * F.S. l1 dan l2 tetap, tidak berubah
 * @return list yang merupakan hasil union antara list pertama dan kedua
 */

int inlist(List l, ElType val)
{
    Address curr = l->next;
    while (curr != NULL) {
        if (curr->info == val) {
            return 1;
        }
        curr = curr->next;
    }
    return 0;
}


List getUnion(List l1, List l2) {
    List result;
    CreateList(&result);
    Address curr1 = l1;
    Address curr2 = l2;

    // Proses semua elemen l1
    while (curr1 != NULL) {
        if (!inlist(result, curr1->info)) {
            insertLast(&result, curr1->info);
        }
        curr1 = curr1->next;
    }

    // Proses semua elemen l2
    while (curr2 != NULL) {
        if (!inlist(result, curr2->info)) {
            insertLast(&result, curr2->info);
        }
        curr2 = curr2->next;
    }

    return result;
}


/**
 * @brief Mengeluarkan hasil intersect dari 2 buah list
 * @param l1 adalah list pertama.
 * @param l2 adalah list kedua.
 * I.S. l1 dan l2 terdefinisi, mungkin kosong.
 * F.S. l1 dan l2 tetap, tidak berubah
 * @return list yang merupakan hasil intersect antara list pertama dan kedua
 */
List getIntersect(List l1, List l2) {
    List result;
    CreateList(&result);
    Address curr1 = l1;

    // Iterasi melalui l1
    while (curr1 != NULL) {
        // Cek jika elemen l1 ada di l2 DAN belum ada di result
        if (inlist(l2, curr1->info) && !inlist(result, curr1->info)) {
            insertLast(&result, curr1->info);
        }
        curr1 = curr1->next;
    }
    return result;
}

/**
 * @brief Melakukan input untuk mendapatkan n (hari). Kemudian untuk setiap n akan menerima input x (jumlah nimons pada hari itu) dan melakukan input list dengan elemen sebanyak x untuk setiap n. Berikan Union dan Intersect akhir yang disimpan ke dalam variabel "Union" dan "Irisan".
 * @param *Union adalah pointer list Union.
 * @param *Irisan adalah pointer list Irisan.
 * I.S. Union dan Irisan terdefinisi dengan elemen awal kosong.
 * F.S. Union dan Irisan berisi hasil union dan intersect seluruh data yang diinputkan.
 */
void getData(List *Union, List *Irisan) {
    int n, x, val;
    scanf("%d", &n);

    List temp, currentList;

    CreateList(Union);
    CreateList(Irisan);

    for (int i = 0; i < n; i++) {
        CreateList(&currentList);
        scanf("%d", &x);
        for (int j = 0; j < x; j++) {
            scanf("%d", &val);
            insertLast(&currentList, val);
        }

        if (i == 0) {
            *Union = currentList;
            *Irisan = currentList;
        } else {
            temp = getUnion(*Union, currentList);
            *Union = temp;

            temp = getIntersect(*Irisan, currentList);
            *Irisan = temp;

        }
    }
}


int main() {
    List Union, Irisan;

    printf("Masukkan jumlah hari dan data nimons per hari:\n");
    getData(&Union, &Irisan);

    printf("\nHasil Union:\n");
    displayList(Union);

    printf("\nHasil Irisan:\n");
    displayList(Irisan);

    // Dealokasi setelah selesai

    return 0;
}