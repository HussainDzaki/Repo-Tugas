#include <stdio.h>

int main(){\
    int n =4;
    int nxt = 0;
    for (int i = 0; i <n; i++)
    {
        nxt += i + 1;
        printf("%d ", nxt);
    }
    return 0;
    
}