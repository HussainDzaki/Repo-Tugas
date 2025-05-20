#include <stdio.h>
#include "stack.h"

int main(){
    Stack S;
    int P;
    CreateEmpty(&S);
    if (IsEmpty(S))
    {
        printf("JAWA\n");
    }
    Push(&S,5);
    Push(&S,4);
    Push(&S,3);
    Push(&S,2);
    Push(&S,1);

    printf("%d\n", S.T[S.TOP]);
    Pop(&S, &P);
    printf("%d\n", S.T[S.TOP]);
    
    return 0;
}