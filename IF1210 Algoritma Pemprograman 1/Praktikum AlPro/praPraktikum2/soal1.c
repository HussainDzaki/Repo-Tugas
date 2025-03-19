#include <stdio.h>
#include <math.h>

double konversi(double suhu, char suhusat1, char suhusat2 ){
    if ((suhusat1 == 'C')&& (suhusat2 =='F')){
        return suhu * 9/5 + 32;
    }
    else if ((suhusat1 == 'C')&& (suhusat2 =='K'))
    {
        return suhu + 273.15;
    }
    else if ((suhusat1 == 'F')&& (suhusat2 =='C'))
    {
        return (suhu -32)*5/9;
    }
    else if ((suhusat1 == 'F')&& (suhusat2 =='K'))
    {
        return (suhu -32)*5/9 + 273.15;
    }else if ((suhusat1 == 'K')&& (suhusat2 =='C'))
    {
        return suhu - 273.15;
    }
    else{
        return (suhu - 273.15)* 9/5 +32;
    }
    
    
    
}


int main(){
    int n;
    double suhuawal;
    char st1, st2;
    scanf("%d", &n);
    for (int i =0; i < n; i++){
        scanf("%lf %c %c", &suhuawal, &st1, &st2);
        printf("%.2lf\n", floor(konversi(suhuawal,st1,st2)));

    }
    return 0;

}