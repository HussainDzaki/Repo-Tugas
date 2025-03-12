// Pola Aneh
// Akan menerima masukan N (0<= N <= 25) kemudian memberikan pola nxn berbentuk permata

#include <stdio.h>
int main(){
    int N;
    int i,j;
    int mid;
    scanf("%d", &N);
    mid = (N-1)/2;
    for(i =0; i < N; i++ ){
        for(j=0; j < N; j++){
            if ( i + j == mid|| (j-i == mid) || (j + i) == (3 * mid) || i-j == mid){
                printf("*");
            }
            else{
                printf(".");
            }
            
            
            
        
        }
        printf("\n");

        }
        
    return 0 ;
    }