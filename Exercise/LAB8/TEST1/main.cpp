#include <iostream>
#include "candybar.h"
using namespace std;

int main(){
    CandyBar c{};

    cout << "Call the set function of Passing by pointer:" << endl;
    setCandyBar(&c);
    cout << endl;

    cout << "Call the show function of Passing by pointer:" << endl;
    showCandyBar(&c);
    cout << endl;
    cin.ignore();
    cout << "Call the set function of Passing by reference:" << endl;
    setCandyBar(c);
    cout << endl;

    cout << "Call the show function of Passing by reference:" << endl;
    showCandyBar(c);
}