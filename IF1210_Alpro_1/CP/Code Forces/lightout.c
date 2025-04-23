#include <stdio.h>

int toggle(int a){
    if (a == 1){
        return 0;
    }else{
        return 1;
    }
}

int main(){
    int matrix[3][3];
    int istate[3][3] = {{1,1,1},{1,1,1},{1,1,1}};
    for (int i = 0; i <3; i++){
        for (int j = 0; j<3; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i<3 ; i++){
        for (int j = 0; j < 3; j++){
            if (matrix[i][j] % 2== 1){
                istate[i][j] = toggle(istate[i][j]);
                if (i < 2)
                {
                    istate[i+1][j] = toggle(istate[i+1][j]);
                }
                if (i > 0){
                    istate[i-1][j] = toggle(istate[i-1][j]);
                }
                if(j < 2){
                    istate[i][j+1] = toggle(istate[i][j+1]);
                }
                if(j > 0){
                    istate[i][j-1] = toggle(istate[i][j-1]);
                }

                
                
            }
        }
    }
    for (int i = 0; i <3; i++){
        for (int j = 0; j<3; j++){
            printf("%d", istate[i][j]);
        }
    printf("\n");
    }
}


  