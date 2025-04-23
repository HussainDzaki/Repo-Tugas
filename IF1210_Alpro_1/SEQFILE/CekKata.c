#include <stdio.h>
#include <string.h>

int main()
{
    FILE *inputFile = fopen("buku.txt", "r");
    if (inputFile == NULL)
    {
        perror("FILE TIDAK BISA DIBUKA");
        return 1;
    }

    char str1[100], str2[100];
    int cnt = 0;
    int totaljawa = 0;
    while (fscanf(inputFile, "%s %s", str1, str2) == 2)
    {
        if (strcmp(str1, "0") == 0 || strcmp(str2, "0") == 0)
        {
            break;
        }

        if (strcmp(str1, str2) == 0)
        {
            cnt++;
        }
        if (strcmp(str1, "jawa") == 0)
        {
            totaljawa++;
        }
        if (strcmp(str2, "jawa") == 0)
        {
            totaljawa++;
        }
    }
    printf("total kata sama : %d\n", cnt);
    printf("total kata jawa : %d\n", totaljawa);

    fclose(inputFile);
}