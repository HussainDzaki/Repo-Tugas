#include <iostream>
#include <vector>
using namespace std;

int main(){
    int q, p;
    cin >> q >> p;
    vector<int> scores(q);
    for (int i =0; i<q; i++){
        cin >> scores[i];
    }

    int threshold = scores[p-1];

    int cnt = 0;
    for(int i =0; i < scores.size();  i++){ // for (int score : scores) {
        if (scores[i] >= threshold && scores[i] > 0 ){
            cnt++; 
        }
    }
    cout << cnt << endl;
    return 0 ;
}