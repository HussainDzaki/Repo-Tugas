#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;

    vector<int> pasukan(n + 1, 0);
    for(int i = 1; i < n + 1; i++){
        cin >> pasukan[i];
    }

    vector<int> answer(q, 0);
    int answerCount = 0;
    for(int i = 0; i < q; i++){
        int perintah = 0;
        cin >> perintah;
        if(perintah == 1){
            int target(0), increment(0);
            cin >> target >> increment;
            for(int j = 1; j < n + 1; j++){
                if(pasukan[j] != target) continue;
                pasukan[j] += increment;
            }
        }
        else{
            int targetIndex = 0;
            cin >> targetIndex;
            answer[answerCount] = pasukan[targetIndex];
            answerCount++;
        }
    }

    for(int i = 0; i < answerCount; i++){
        cout << answer[i] << "\n";
    }

    return 0;
}