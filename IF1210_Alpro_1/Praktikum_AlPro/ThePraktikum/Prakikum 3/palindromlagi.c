#include <stdio.h>
#include <string.h>

int cekBisaPalindrom(char arr[])
{
    int count[1001] = {0};

    for (int i = 0; arr[i] != '\0'; i++)
    {
        count[(int)arr[i]]++; 
    }

    int odd = 0;
    for (int i = 0; i < 1001; i++)
    {
        if (count[i] % 2 != 0)
            odd++;

        if (odd > 1)
            return 0;
    }

    return 1;
}

int main()
{
    char s[1001];
    scanf("%s", s);

    if (cekBisaPalindrom(s))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}