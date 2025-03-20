#include <stdio.h>



int totalPisang(int p1, int p2, int p3,int p4,int p5){
    return p1 +p2 + p3 + p4 + p5;

}

float rataPisang(int total){
    return total/5;
}

void pesanPesta(float rata){
    if (rata >= 10){
        printf("Pesta Nimons Sukses!\n");
    }else{
        printf("Pesta Nimons Gagal, kumpulkan lebih banyak pisang!\n");
    }
}

int main(){
    int a,b,c,d,e;
    scanf("%d %d %d %d %d", &a,&b,&c,&d,&e);
    printf("%d\n", totalPisang(a,b,c,d,e));
    printf("%f\n",rataPisang(totalPisang(a,b,c,d,e)));
    pesanPesta(rataPisang(totalPisang(a,b,c,d,e)));
    return 0;


}