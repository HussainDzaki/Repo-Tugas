#include <stdio.h>

int main(){
    int i, j, sum, N, num;
    sum = 1;
    scanf("%d", &N);
    for (i = 0; i< N; i++ ){
        for (j = 0; j< N ; j++){
            num = j+i;
            if((i + j) <= N/2 + 1){
                sum = 1;
                num += sum;
                }
            else if((i+j) == N +1 ){
                sum = -N + 1;
                num += sum;
                }
            else if ((i+j) > N/2   ){
                sum = -1;
                num += -1;
                
            }
            printf("%d ", num);
        }
        printf("\n");
    }
    return 0;
}