#include <stdio.h>
#include <stdlib.h>
// #include "tester.h"

/* Tulis kode disini jika perlu */

typedef struct
{
    int id;
    int sucs;
    int missionval;
} DataNimons;

void insertionsort(DataNimons data[], int n)
{   
    DataNimons key;
    int i ;
    if (n > 1)
    {
        for (int pass = 1; pass < n; pass++)
        {
            key  = data[pass];
            i = pass - 1;
            while ((data[i].sucs > key.sucs) || (data[i].sucs == key.sucs && data[i].missionval > key.missionval) ||  (data[i].sucs == key.sucs && data[i].missionval == key.missionval && data[i].id > key.id) && (i >= 0))
            {
                data[i + 1] = data[i];
                i--;
            }
            data[i+1] = key;
        }
    }
}

void printhasil(DataNimons data[], int arr[], int arg){
    for (int i = 0; i < arg; i++)
    {   
        
        printf("%d %d\n", data[arr[i] - 1].id, data[arr[i] - 1].missionval );
    }
    
}


int returnNeff(DataNimons arr[]){
    int i = 0;
    while (arr[i].id != -1)
    {
        i++;
    }
    return i;
    
    
}

int main()
{
    // init();
    /* Tulis kode dibawa ini */
    FILE *queryFile = fopen("query.txt", "r");
    FILE *inputFile = fopen("input.txt", "r");

    int arg;
    if (queryFile == NULL)
    {
        perror("File query.txt gagal dibuka");
        return 1;
    }
    fscanf(queryFile, "%d", &arg);
    int arrarg[arg];
    int a;
    for (int i = 0; i < arg; i++)
    {
        fscanf(queryFile, "%d", &a);
        arrarg[i] = a;
    }

    if (inputFile == NULL)
    {
        perror("File input.txt gagal dibuka");
        return 1;
    }

    int id, sucs, val;

    DataNimons ArrDataNimons[1000];

    int i = 0;
    while (fscanf(inputFile, "%d %d %d", &id, &sucs, &val) == 3)
    {
        if (id == -1 && sucs == 0 && val == 0)
        {
            ArrDataNimons[i].id = -1;
            ArrDataNimons[i].missionval = 0;
            ArrDataNimons[i].sucs = 0;
            break;
        }

        ArrDataNimons[i].id = id;
        ArrDataNimons[i].missionval = val;
        ArrDataNimons[i].sucs = sucs;
        i++;
    }

    insertionsort(ArrDataNimons, returnNeff(ArrDataNimons));

    printhasil(ArrDataNimons, arrarg, arg);
    


    fclose(queryFile);
    fclose(inputFile);

    // TODO: baca file input.txt
    // TODO: baca file query.txt
    // TODO: tulis kode untuk algoritma utama
    // TODO: close file input.txt
    // TODO: close file query.txt
    return 0;
}