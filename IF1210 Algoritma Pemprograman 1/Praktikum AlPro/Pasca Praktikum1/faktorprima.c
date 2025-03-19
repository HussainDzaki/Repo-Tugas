
#include <stdio.h>

int main(){
     int n;
    int fac, exp, pertama;
    scanf("%d",&n);
    pertama = 1;

    
    if (n%2 == 0){
        exp = 0;
        while(n  %2 == 0){
            n /= 2;
            exp ++;
        }
        if (exp > 0){
            if (!pertama) printf(" * ");
            if(exp == 1){
                printf("2");
            }
            else{printf("2^%d", exp);};
            pertama = 0;
        }
    }

    for(fac = 3; fac*fac <= n; fac += 2){
        if(n % fac == 0){
            exp = 0;
            while ( n % fac ==0)
            {
            n/= fac;
            exp ++;
            }
            if(exp >0){
                if (!pertama) printf(" * ");
                if(exp == 1){
                    printf("%d", fac);
                }
                else{
                    printf("%d^%d", fac,exp);
                }
                pertama = 0;
            }
        }
    }
    if (n>2){
        if(!pertama) printf(" * ");
        printf("%d", n);
    }
    printf("\n");
    return 0;
    }