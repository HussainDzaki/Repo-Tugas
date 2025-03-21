#include <stdio.h>

int main(){
    int uts,uas,sum, akhir,i;
    float rata;
    scanf("%d",&uts);
    if(uts <0 || uts > 100){
        printf("Data kosong");
    }
    else{
        i = 1;
        sum = 0;
        do{
            for(;;){
            scanf("%d", &uas);
            if( uas >= 0 && uas <= 100){
                break;
            }
            else{
                printf("Data tidak valid\n");
            }
        }
        sum  = uts * 0.4 + uas * 0.6;
        printf("Rata-rata pelajaran %d adalah %d\n", i , sum);
        akhir += sum;
        scanf("%d", &uts);
        i ++;
        }while (!(uts < 0 || uts > 100));
        i = i -1;
        rata = akhir / i;

        printf("%f, %d, %d", rata, akhir, i);
        

    }
}