#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1e6 + 5;

vector<bool> isPrime(MAX, true);
vector<int> prefixSum(MAX, 0);

void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < MAX; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < MAX; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i < MAX; ++i) {
        prefixSum[i] = prefixSum[i - 1] + (isPrime[i] ? 1 : 0);
    }
}

int main() {
    sieve();
    int Q;
    cin >> Q;
    while (Q--) {
        int L, R;
        cin >> L >> R;
        cout << prefixSum[R] - prefixSum[L - 1] << endl;
    }
    return 0;
}