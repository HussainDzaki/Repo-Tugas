#include <stdio.h>

int main(){
    long long int n;
    long int sum;
    scanf("%lld", &n);
    sum = 0;
    if(n %2 == 0){
        n = n /2  ;
        printf("%lld\n",n);
    }else{
        n = n/2 +1 ;
        printf("%lld\n", n * -1) ;
    }
    return 0;
    }
    



