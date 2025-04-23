#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int nxt = 1;
    for (int i = 0; i < n; i++)
    {
        int opo = 1;
        opo = nxt;
        nxt += i + 1;
        for (int j = 0; j < n; j++)
        {
            if (i + j <= n - 1)
            {
                opo += i + j;
                printf("%d", opo);
            }

            else
            {
                opo += ((n - 1) * 2) - (i + j) + 1;
                printf("%d", opo);
            }
            if (j < n - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
