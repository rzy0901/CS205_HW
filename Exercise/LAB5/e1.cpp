#include <iostream>

using namespace std;

int main() {
    bool a = true;
    int temp;
    int sum = 0;
    while (a)
    {
        cout << "Enter an integer number: ";
        cin >> temp;
        sum += temp;
        cout << "The cumulative sum of the entries to date is "<< sum << endl;
        if(temp == 0){
            a = false;
        }
    }
}