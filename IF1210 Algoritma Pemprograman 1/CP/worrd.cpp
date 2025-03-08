#include <iostream>
#include <string>
using namespace std;

int main()
{
    int x,lgh;
    cin >> x;

    for (int i=0; i < x; i++)
    {
        string word;
        cin >> word;
        lgh = word.length();
        if (lgh <= 10){
            cout <<word<<"\n";
        }
        else {cout << word[0] << lgh - 2 << word[word.length() - 1]<<"\n";}
        
    }
    return 0;
}
