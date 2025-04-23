#include <stdio.h>
#include <stdlib.h>
#include "tester.h"

/* Tulis kode disini jika perlu */

int main() {
    init();
    FILE *fileinput = fopen("input.txt", "r");
    if (fileinput == NULL){
        perror("File input.txt gagal dibuka");
        return 1;
    }
    int id = 0, sucs =0 , value=0, totmisi=0, misiberhasil=0, sumvalue=0;

    while (fscanf(fileinput, "%d %d %d", &id, &sucs, &value) == 3)
    {
        if (id == -1 && sucs == 0 && value == 0)
        {
            break;
        }

        if( sucs == 1){
            misiberhasil = misiberhasil + 1;
            sumvalue = sumvalue + value;
        }
        totmisi++;
        
    }
    
    printf("Total Misi: %d\n", totmisi);
    printf("Misi Berhasil: %d\n", misiberhasil);
    printf("Total Nilai Misi: %d\n", sumvalue);



    fclose(fileinput);
    /* Tulis kode dibawa ini */
    // TODO: baca file input.txt

    // TODO: tulis kode untuk algoritma utama
    // TODO: close file input.txt
    return 0;
}