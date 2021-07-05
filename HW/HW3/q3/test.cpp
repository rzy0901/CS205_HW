#include <iostream>
#include <cstring>
using namespace std;
#include <stdio.h>

int main() {
    char* a=0,b=0,c=0;
    while (!cin.eof())
    {
        cin >> a;
        cin >> b;
        cin >> c;
        cout <<"a"<<a<<"b"<<b<<"c"<<c<<endl;
    }
    // Ctrl + D 停止输入
    cout<<"nihao"<<endl;
    return 0;
}
