#include <stdio.h>
#include <string.h>
int main(){
    FILE *oFile; 
    oFile = fopen("buku.txt", "a");
    if (oFile == NULL)
    {
        perror("Anjay filenya engga bisa dibuka");
        return 1;
    }
    char str[100];

    while (fgets(str, sizeof str, stdin) != NULL)
    {   
        str[strcspn(str, "\n")] = '\0';

        if (strcmp(str, "STOP") == 0) {
            break;}


        fprintf(oFile, "%s\n", str);
        
    }
    
    
    
    fclose(oFile);
    return 0;
}