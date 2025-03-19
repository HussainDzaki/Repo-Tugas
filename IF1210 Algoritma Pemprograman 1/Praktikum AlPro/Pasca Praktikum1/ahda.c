#include <stdio.h>

int main(){
    int x,y; //koordinat
    int h; //ketersediaan
    int n; //ukuran
    int update;
    update=1;
    int angka;
    int jebol,xjebol,yjebol;
    int lewat,xlewat,ylewat;
    scanf("%d",&n);
    x=1; y=1;
    angka=1;
    int i,j;//for
    xjebol=2-n;
    yjebol=2*n-1;
    xlewat=0;
    ylewat=0;
    h=n;//ketersediaan slot horizontal dan vertikal adalah sama dengan ukuran
    for (i=1;i<=n;i++){
        x=1;y=i;
        xlewat=1-i; ylewat=n+i-1;
        for(j=1;j<=n;j++){
            if (i<=2){ //kalau cuman 2 baris buat khusu saja
                if(x==1 &&y==i){ //mulainya selalu dari 1,1 trs turun ke 0,-2
                    if (angka<10){
                        printf(" %d", angka);
                        }
                        else{
                            printf("%d ",angka);
                        }
                    angka+=1;
                    h-=1;
                }

                else if(x>1-i && y<n+i-1){
                    angka+=1;
                    j-=1;
                }
                else if(y==n+i-1 || x==1-i){
                    if (angka<10){
                        printf("  %d", angka);
                        }
                        else{
                            printf(" %d",angka);
                        }
                    angka+=1;
                    x=n-h+1;
                    h-=1;
                    y=i;
                }
            }
            else if (i>2 && i<n) {//mulai dari baris 3 sudah anomali
                
                if (lewat==0){
                    if(x==1 &&y==i){
                        if (angka<10){
                            printf(" %d", angka);
                            }
                            else{
                                printf("%d",angka);
                            }
                        angka+=1;
                        h-=1;
                    }
                    else if(x==xlewat && y<ylewat){
                        if (angka<10){
                            printf("  %d", angka);
                            }
                            else{
                                printf(" %d",angka);
                            } //print angka dulu
                        angka+=1;
                        x=n-h+1; //pindah ke koordinat angka
                        h-=1; //kurang terakhir karena kan harus pindah koordinat ke yang kosong dulu
                        y=i;
                    }
                    else if(x==xlewat && y==ylewat){ //kalau sampai koordinat anomali
                        if (angka<10){
                            printf("  %d", angka);
                            }
                            else{
                                printf(" %d",angka);
                            }
                        angka+=1;
                        x=n-h+1;
                        h-=1;
                        y=i;
                        xlewat+=1; //awalnya cuman geser 1
                        lewat+=1;
                    }
                    else{
                        angka+=1;
                        j-=1;
                    }
                }
                else if(lewat>=1){
                    if(x==xlewat && y==ylewat){
                        
                        if (lewat==i){ //dia cuman ada angka yg anomali(lewat) n baris -1, karena pas akhir dia tetap tambah 1 maka break di kondisi kalau n baris= counter anomali(lewat)
                            if (angka<10){
                                printf("  %d", angka);
                                }
                                else{
                                    printf(" %d",angka);
                                }
                            break;
                        }
                        else{
                            if (angka<10){
                                printf("  %d", angka);
                                }
                                else{
                                    printf(" %d",angka);
                                }
                            angka+=1;
                            x=n-h+1;
                            h-=1;
                            y=i;
                            xlewat+=2; //lalu batas cetak di samping bergesar jadi ke kanan 2 ke atas 1
                            ylewat-=1;
                            lewat+=1;
                        }
                    }
                    else{
                        angka+=1;
                        j-=1;
                    }
                }
                

            }
            else if (i==n && n>=3){ //kalau sudah terakhir dia sudah anomali, kalau dia mencapai koordinat batas atau 2-baris skrg dan 2*baris skrg-1
                if (x==1 && y==i){
                    if (angka<10){
                        printf(" %d", angka);
                        }
                        else{
                            printf("%d",angka);
                        }
                    angka+=1;
                    h-=1;
                }
                else if(x==xjebol && y==yjebol){
                    if (angka<10){
                    printf("  %d", angka);
                    }
                    else{
                        printf(" %d",angka);
                    }
                    angka+=1;
                    x=n-h+1;
                    h-=1;
                    y=i;
                    xjebol=xjebol+2; //lalu koordinat tanda cetak angka menjadi +2 ke kanan dan 1 ke atas
                    yjebol=yjebol-1;
                }
                else{
                    angka+=1;
                    j-=1;
                }
                
            }
            x-=1; y+=1; //selalu ke kiri 1(-x) dan turun 1 langkah(+y)
        }
        //selesai 1 baris
        printf("\n");
        h=n; 
        angka=1; //balik angka awal
        update+=i; //awalnya tambah 2, kemudian secara bertahap bertambah 1
        angka+=update;//buat angka awalnya sesuai yang baris selanjutnya
        update=angka;//angka yang akan digunakan buat nentuin baris selanjutnya lagi
        lewat=0;
    }
    return 0;
}