#include <iostream>
#include <cctype>
using namespace std;

int main(){
    string word;
    cin >> word;

    int upperCount = 0;
    int lowerCount = 0;

    for ( int i = 0 ; i <= word.length();  i++){
        if (isupper(word[i]))
        {
            upperCount ++;
        } else {
            lowerCount ++;
        } 
    }
    
    if (upperCount >= lowerCount){
        for (int i = 0 ; i <= word.length();  i++){
            word[i] = toupper(word[i]);
        }
    } else{
        for (int i = 0 ; i <= word.length();  i++){
            word[i] = tolower(word[i]);
        }
    }

    cout << word;
}