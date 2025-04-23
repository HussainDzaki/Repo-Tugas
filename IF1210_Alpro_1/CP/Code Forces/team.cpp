#include <iostream>
using namespace std;

int main(){
    int x,i, count; 
    int p,v,t;
    count = 0;
    cin >> x;
    for (i = 0; i < x; i++){
        cin >> p >> v >> t;
        if (p + v + t >= 2){
            count += 1;
        }else{ count += 0 ;}
    }
    cout << count << "\n";
    return 0;
}