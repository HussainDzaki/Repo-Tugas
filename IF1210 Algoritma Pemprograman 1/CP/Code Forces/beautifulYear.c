#include <stdio.h>

int main(){
    int year, a,b,c,d;
    scanf("%d", &year);

    do{
        year += 1;
        a = year / 1000;
        b = (year / 100) % 10;
        c = (year / 10) % 10;
        d = year % 10;
    }while ((a==b) || (a == c) || (a ==d) || (b == c) || (b == d) || (c == d) );
    printf("%d\n", year);
    return 0;
    
}