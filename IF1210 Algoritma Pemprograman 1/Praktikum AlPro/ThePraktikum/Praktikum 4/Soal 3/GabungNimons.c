#include <stdio.h>
#include "tester.h" // Comment this when developing in local
int main()
{
    init(); // Comment this when developing in local

    FILE *filea = fopen("file_a.txt", "r");
    FILE *fileb = fopen("file_b.txt", "r");

    typedef struct
    {
        int ID;
        int VAL;
    } datanimos;

    int idA, jmlpisangA, idB, jmlpisangB;
    while (fscanf(filea, "%d %d", &idA, &jmlpisangA) == 2 && fscanf(fileb, "%d %d", &idB, &jmlpisangB) == 2)
    {
        if (idA <= idB)
        {
            
        }
    }

    fclose(filea);
    fclose(fileb);
    return 0;
}