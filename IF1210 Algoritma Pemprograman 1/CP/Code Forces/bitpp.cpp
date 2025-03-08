#include <iostream>
using namespace std;
#include <string>
int main()
{
    int x, i, count;
    string opra;
    cin >> x;
    count = 0;
    for (i = 0; i < x; i++)
    {
        cin >> opra;
        if ((opra == "++X")|| (opra == "X++"))
        {
            count += 1;
        }
        else if ((opra == "--X") || (opra == "X--"))
        {
            count -= 1;
        }
        else
        {
            count += 0;
        }
    }
    cout << count ;
    return 0;
}