#include <stdio.h>

int main(){
    long long int p0, k, jam, pop, i;

    scanf("%lld %lld %lld",&p0, &jam, &k);
    i = 0;
    pop = p0;
    for (; i < jam; i++)
    {
        pop = pop * k + p0;
        
    }
    
    printf("Terdapat %lld Virus Nimons Gila pada jam ke-%lld\n", pop,jam);
    return 0;
}