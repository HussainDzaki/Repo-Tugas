#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int q, l, r;
    cin >> q;

    // check all prime in bound
    vector<int> isNotPrime(1000000 + 1, 0);
    isNotPrime[0] = 1;
    isNotPrime[1] = 1;
    for(int i = 2; i <= 1000000; i++){
        if(isNotPrime[i] > 0){
            continue;
        }
        else{
            for(int j = 2*i; j <= 1000000; j += i){
                isNotPrime[j] = 1;
            }
        }
    }

    vector<int> answer(q, 0);
    for(int i = 0; i < q; i++){
        cin >> l >> r;
        for(int j = l; j <= r; j++){
            if(isNotPrime[j]){
                continue;
            }
            answer[i] += 1;
        }
    }

    for(int i = 0; i < q; i++){
        cout << answer[i] << "\n";
    }

    return 0;
}