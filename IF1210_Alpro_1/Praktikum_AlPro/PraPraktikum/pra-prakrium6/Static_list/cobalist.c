#include "liststatik.c"
#include <stdio.h>
#include "Boolean.h"
int main(){
    ListStatik list1, list2;
    ElType p1;
    ElType p2;
    CreateListStatik(&list1);
    CreateListStatik(&list2);
    readList(&list1);
    readList(&list2);

    printf("%d\n", isFront(list1,list2));
    
    printList(list1);
    printList(list2);
    
    return 0;

}