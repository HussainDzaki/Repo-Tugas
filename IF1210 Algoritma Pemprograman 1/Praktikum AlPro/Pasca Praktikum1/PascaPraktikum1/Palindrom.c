#include <stdio.h>

int main(){
    int n, temp, rev, digit ;
    scanf("%d", &n);

    rev = 0;
    for (temp = n; temp > 0 ; temp /= 10){
        digit = temp % 10;
        rev = rev * 10 + digit;
    }

    if (rev == n) {
        printf("1\n");
    }
    else{
        printf("0\n");
    }

    return 0;
}