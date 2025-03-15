#include <stdio.h>

int main(){
    int N,i, cnt;
    scanf("%d", &N);
    i = 0;
    cnt = 0;
    while (i <= N)
    {
        if((N % (i*i)) == 0){
            cnt += 1;
        }
        i++;
    }
    printf("%d\n", cnt);
    return 0;
    // 1 2 4 10  20 25 
}