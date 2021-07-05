#include <iostream>
using namespace std;

int SUM(const int n)
{
    if(n<0) exit(0);
    if(n<5) return 0;
    int m=n/5;
    return m+SUM(m);
}

int main()
{
    int n;
    cin >> n;
    cout<<SUM(n)<<endl;
    return 0;
}