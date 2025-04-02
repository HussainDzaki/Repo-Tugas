#include <stdio.h>
#include <string.h>

int BisaPalindrom(char kata[]){
    int jumlahhuruf[129] = {0};
    int odd = 0;

    for (int i = 0; kata[i] != '\0'; i++)
    {
        jumlahhuruf[(int)kata[i]]++;
    }

    for (int i = 0; i < 129 ; i++)
    {
        
        
        if (jumlahhuruf[i] % 2 != 0)
        {
            odd++;
        }
        if (odd > 1)
        {   
            return 0;
        }
    }
    return 1;
    
    
}
int main()
{
    char s[1001];
    scanf("%s", s);

    if (BisaPalindrom(s))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}