#include <stdio.h>

int main(){
    int n;
    int temp,div;
    int rev =0;
    scanf("%d",&n);
    temp = n;
    for (; temp > 0; temp/= 10)
    {
        div = temp % 10;
        rev = rev * 10 + div;
    }

    if (rev == n){
        printf("1");
    }else{
        printf("0");
    }
    
}