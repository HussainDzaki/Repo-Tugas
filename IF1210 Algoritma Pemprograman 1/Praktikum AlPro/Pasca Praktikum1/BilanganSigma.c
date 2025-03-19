#include <stdio.h>

int main(){
    unsigned int N;
    int i, cnt;
    scanf("%d", &N);
    cnt = 0;
    for(i = 1; i<= N; ++i){
        if (N % i == 0){
            int s = 1;
            while (s*s < i){
                s++;
            }
            if (s*s == i){
                cnt++;
            }
        }
    }

    printf("%d\n", cnt);
    return 0;
    // 1 2 4 10  20 25 
}