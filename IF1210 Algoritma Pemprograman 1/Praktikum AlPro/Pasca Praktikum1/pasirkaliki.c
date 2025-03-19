#include <stdio.h>

int main(){
    int n ;
    scanf("%d" , &n);

    for(int i = 0 ; i < n; i++ ){
        long long int now = 1;
        for( int k = (n-1) - i; k > 0; k--){
            printf(" ");
        }
        for(int j = 0 ; j<= i ; j++){
            if( j == 0){
                printf("%lld", now);
            }
            else{
                now = now * (i-(j-1))/(j);
                printf("%lld", now);
            }
            if (  j == i){
                 printf("\n");
            }else{
                printf(" ");
            }
            
        }
    }
}