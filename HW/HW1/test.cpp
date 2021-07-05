#include <iostream>
#include <sstream>

using namespace std;

template<typename T>
T stringToNum(string str) {
    istringstream iss(str);
    T num;
    iss >> num;
    return num;
}

int main() {
    string str1 = "123.123";
    string str2 = "-12.12";
    cout << stringToNum<double>(str1) << endl;
    cout << stringToNum<double>(str2) << endl;
    return 0;
}