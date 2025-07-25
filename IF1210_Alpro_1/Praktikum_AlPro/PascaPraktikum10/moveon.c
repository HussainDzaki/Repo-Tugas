#include <stdio.h>
#include "listlinier.h"

void removeAll(List *l, ElType val) {
    // int N;
    // scanf("%d", &N);

    // List Kenangan;
    // CreateList(&Kenangan);
    // int d;
    // for (int i = 0; i < N; i++)
    // {   
    //     scanf("%d", &d);
    //     insertLast(&Kenangan, d);
    // }
    
    
    // int val;
    // scanf("%d", &val);
    int len = length(*l);


    List list2;
    CreateList(&list2);
    Address p = *l;
    for (int i = 0; i < len; i++)
    {   
        if(p->info != val) {
            insertLast(&list2, p->info);
        }
        p = p->next;
    }
    
    displayList(list2);
    printf("\n");
}
// int main(){
    

// }