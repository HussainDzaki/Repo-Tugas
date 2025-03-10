#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int matriks[5][5];
    int row = 0; int col = 0;

    for (int i = 0 ; i < 5 ; i++){
        for (int j = 0 ; j <5 ; j++){
            cin >> matriks[i][j];
            if (matriks[i][j] == 1){
                row = i;
                col = j;
            }
        }
    }
    int moves;
    moves = abs(2 - row) + abs(2 - col);
    cout << moves << endl;
    return 0;
}