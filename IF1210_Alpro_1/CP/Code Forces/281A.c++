#include <iostream>
#include <cctype>
using namespace std;
int main(){
    string B;
    int cap;

    cin >> B;

    if (!isupper(B[0])){
        B[0] = toupper(B[0]);
    }
//     if ( isupper(B[0]) ){
//         for(int i =1 ;i <= B.length(); i ++){
//             if (isupper(B[i])){
//                 B[i] = tolower(B[i]);
//             }
            
//         }
//     }else{
//         B[0] = toupper(B[0])
//         for(int i =1 ;i <= B.length(); i ++){
//         if (isupper(B[i])){
//             B[i] = tolower(B[i]);
//             }
            
//     }

    
// }

cout << B ;
}