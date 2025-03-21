#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", -(n ^ -16));
    // printf("%d", (n & 8) >> 3 & (n & 4) >> 2 & (n & 2) >> 1 & (n & 1) & !((n >> 4) & 0));
    return 0;
}