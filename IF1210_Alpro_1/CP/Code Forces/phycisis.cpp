#include <iostream>
using namespace std;
int main(){
    int n,i,x,y,z,sumx,sumy,sumz;
    cin >> n;
    sumx= sumy=sumz = 0;

    for (i =0; i < n; i++){
        cin >> x>>y>>z;
        sumx += x;
        sumy += y;
        sumz += z;
        
    }
    if ((sumx ==0 && sumy==0 && sumz==0)){
        cout << "YES" << "\n";
    }else{
        cout << "NO" << "\n";
    }
    
    return 0;
}