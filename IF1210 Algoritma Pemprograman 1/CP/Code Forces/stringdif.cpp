#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
    string a,b;
    cin >> a >> b;

    for (int i = 0 ; i < a.length(); i++){
        a[i] = tolower(a[i]);
    }
    for (int i = 0 ; i < b.length(); i++){
        b[i] = tolower(b[i]);}
    
    if (a == b){
        cout << 0 <<endl;
    }else if (a < b){
        cout << -1 <<endl;
    }else(cout << 1 << endl);

    
    return 0 ;
}
