#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string temp;
    int count = 0;
    cout << "Enter words(to stop, type the word done):"<<endl;
    while (true)
    {
        cin >> temp;
        if(temp != "done"){
            count++;
        }else{
            break;
        } 
    }
    cout << "You entered a total of "<<count<<" words."<<endl;
}