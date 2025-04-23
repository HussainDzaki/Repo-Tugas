#include <stdio.h>
#include "tester.h" // Comment this when developing in local
int main()
{
    init(); // Comment this when developing in local

    FILE *filea = fopen("file_a.txt", "r");
    FILE *fileb = fopen("file_b.txt", "r");

    int idA, jmlpisangA, idB, jmlpisangB;
    int readA, readB;
    
    readA = fscanf(filea, "%d %d", &idA, &jmlpisangA);
    readB = fscanf(fileb, "%d %d", &idB, &jmlpisangB);
    while (readA == 2 &&  readB == 2 && idA != -1 && jmlpisangA != -99 && idB != -1 && jmlpisangB != -99)
    {
        if (idA < idB)
        {
            printf("%d %d\n", idA, jmlpisangA);
            readA = fscanf(filea, "%d %d", &idA, &jmlpisangA);
        }
        else
        {
            printf("%d %d\n", idB, jmlpisangB);
            readB = fscanf(fileb, "%d %d", &idB, &jmlpisangB);
        }
    }

    
    while (readA == 2 && idA != -1 && jmlpisangA != -99)
    {
        printf("%d %d\n", idA, jmlpisangA);
        readA = fscanf(filea, "%d %d", &idA, &jmlpisangA);
    }
    
    while (readB == 2 && idB != -1 && jmlpisangB != -99)
    {
        printf("%d %d\n", idB, jmlpisangB);
        readB = fscanf(fileb, "%d %d", &idB, &jmlpisangB);
    }

    fclose(filea);
    fclose(fileb);
    return 0;
}