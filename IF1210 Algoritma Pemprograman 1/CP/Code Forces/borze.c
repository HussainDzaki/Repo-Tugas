#include <stdio.h>
#include <string.h>

int main(){
    char borze[201]; 
    int i;
    scanf("%s", borze);

    i = 0;
    while (borze[i] != '\0'){
        if (borze[i] == '.'){
            printf("0");
            i ++;
        }
        else if (borze[i]== '-'){
            if (borze[i+1] == '.'){
                printf("1");
                i += 2;
            }else if (borze[i+1] == '-'){
                printf("2");
                i += 2;
            }
        }

        
    }
    printf("\n");
    return 0 ;
}