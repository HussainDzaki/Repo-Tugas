#include <stdio.h>

int main(){
    int i, j, N, num, jir;
    scanf("%d", &N);
    jir = 1;
    for (i = 0; i < N; i++ ){
        for (j = 0; j < N ; j++){
            num = j + i + 1;  // Penyesuaian nilai awal num
            // Jika berada di bagian awal (sebelum titik balik)
            if (j < N -i -1 ) {  
                jir += num;
                
            }
            // Jika berada di bagian akhir (setelah titik balik)
            else {
                jir += num;
                num = N - (j - (N - i - 1)); // Mengatur angka menurun
                
                
            }
            printf("%d ", num);
        }

        printf("\n");
    }
    return 0;
}