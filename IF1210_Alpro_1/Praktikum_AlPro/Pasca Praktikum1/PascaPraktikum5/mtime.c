#include "time.h"
#include "boolean.h"
#include <stdio.h>

int main()
{
    int nrecord;
    scanf("%d", &nrecord);
    TIME T1;
    TIME T2;
    TIME MAX, MIN;
    CreateTime(&MAX,0,0,0);
    CreateTime(&MIN,23,59,59);
;
    for (int i = 0; i < nrecord; i++)
    {   
        printf("[%d]\n", i +1 );
        BacaTIME(&T1);
        BacaTIME(&T2);

        if (TGT(T1, T2))
        {
            if (TLT(T2, MIN))
            {
                MIN = T2;
            }
            if (TGT(T1, MAX))
            {
                MAX = T1;
            }
            printf("%ld\n", Durasi(T2, T1));
        }
        else
        {
            if (TLT(T1, MIN))
            {
                MIN = T1;
            }
            if (TGT(T2, MAX))
            {
                MAX = T2;
            }
            printf("%ld\n", Durasi(T1, T2));
        }
    }
    TulisTIME(MIN);
    printf("\n");
    TulisTIME(MAX);
    printf("\n");
    return 0;
}