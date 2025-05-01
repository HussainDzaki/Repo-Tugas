#include "liststatik.c"
#include <stdio.h>
#include "Boolean.h"
int main(){
    ListStatik list1, list2;
    CreateListStatik(&list1);
    CreateListStatik(&list2);
    printf("%d %d %d\n", isIdxValid(list1, 100), isIdxValid(list1, 99), isIdxValid(list1, -1));
    readList(&list1);
    readList(&list2);
    printList(list1);
    printf("\n");
    printList(list1);
    printf("\n");
    
    printf("List 1: ");
    printList(list1);
    printf("\n");
    sortList(&list1, 0);
    printf("List 1: ");
    printList(list1);
    printList(list2);
    printf("\n");

    printf("%d\n", isListEqual(list1,list2));
    return 0;

}