#include <stdio.h>

int main(){
    /* KAMUS */
    FILE *f;
    char cc;
    int retval;
    /* ALGORITMA */

    f = fopen("dataku.txt", "r");
    retval = fscanf(f, "%c", &cc);
    if (cc == '.')
    {
        printf("File kosong");
    }else{  
        do
        {
            printf("%c", cc);
            retval = fscanf(f,"%c", &cc);
        } while (cc != '.');
        
    }
    


    fclose(f);
}