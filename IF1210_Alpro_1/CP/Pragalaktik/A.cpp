#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    cout
}