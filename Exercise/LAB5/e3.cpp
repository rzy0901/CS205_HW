#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int vn = 5;
const char vowel[vn] = {'a','e','i','o','u'};

int main() {
    cout << "Enter word (q to quit):" << endl;
    int nVowel = 0;
    int nConsonant = 0;
    int nOther = 0;
    char word[30];

    while (cin >> word)
    {
        if(isalpha(word[0])){
            if(strlen(word) == 1 && word[0] == 'q')
                break;
            char x = tolower(word[0]);
            for (size_t i = 0; i < 5; i++)
            {
                if(x == vowel[i]){
                    nVowel++;
                    break;
                }
                if(i==4 && x != 'u'){
                    nConsonant++;
                }
            }    
        }else{
            nOther++;    
        }       
    }
    cout << nVowel << " words beginning with vowels" << endl
    << nConsonant << " words beginning with consonats" << endl
    << nOther << " others" << endl;
    return 0;
}