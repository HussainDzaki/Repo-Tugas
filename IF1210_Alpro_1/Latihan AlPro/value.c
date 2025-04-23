#include <stdio.h>


typedef unsigned char *pointer;

void show_bytes(pointer start, size_t len){
    size_t i ;
    for (i = 0 ; i <len; i++)
        printf("%p\t0x%.2x\n", start+i, start[i]);
    printf("\n");
}

int main(){
    int a = 20;
    float b = 0;
    float c = -0;
    // printf("int a = 1000;\n");
    // show_bytes((pointer) &a, sizeof(int));
    printf(b>c);
    return 0;
}