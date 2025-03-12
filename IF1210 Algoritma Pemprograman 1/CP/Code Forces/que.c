#include <stdio.h>
#include <string.h>

int main(){
    int x, t, j;
    char temp;
    scanf("%d %d",&x, &t);
    x = x +1;
    char arr[x];
    scanf("%s", arr);
    for(int i=0; i < t; i++){
        j = 0;
        while ( j < x-1 )
        {
            if ( arr[j] == 'B' && arr[j+1] == 'G'){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                j = j + 2;
            }   
            else{
                j = j + 1;
            }

        }
        


    }
    printf("%s\n", arr);
    return 0;
}