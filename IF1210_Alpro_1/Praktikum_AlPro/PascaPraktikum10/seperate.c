#include "listlinier.h"
#include "stdio.h"

/* I.S. l terdefinisi, mungkin kosong */
/* F.S. List l diatur ulang sehingga semua bilangan ganjil muncul sebelum bilangan genap */
/*      dengan mempertahankan urutan relatif dalam setiap kelompok */

// int isGenap(ElType bil)
// {
//     if (bil % 2 == 0) {
//         return 1;
//     }
//     else return 0;
// }



void separateOddEven(List *l)
{
    if (isEmpty(*l)) return;

    List oddList, evenList;
    CreateList(&oddList);
    CreateList(&evenList);

    Address p = *l;
    while (p != NULL) {
        if (INFO(p) % 2 != 0) { 
            insertLast(&oddList, INFO(p));
        } else {
            insertLast(&evenList, INFO(p));
        }
        p = NEXT(p);
    }

    *l = concat(oddList, evenList);
}



// int main()
// {
//     List l;
//     CreateList(&l);
//     insertLast(&l, 1);
//     insertLast(&l, 2);
//     insertLast(&l, 3);
//     insertLast(&l, 4);
//     insertLast(&l, 5);
//     insertLast(&l, 11);
//     separateOddEven(&l);
//     displayList(l);
// }
