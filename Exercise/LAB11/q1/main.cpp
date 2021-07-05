#include <iostream>
#include "complex.h"
using namespace std;
int main()
{
    Complex a(3.0, 4.0);
    Complex b(2.0, 6.0);

    cout << "a is " << a << endl;
    cout << "b is " << b << endl;
    cout << "~b is " << ~b << endl;
    cout << "a+b is " << a + b << endl;
    cout << "a-b is " << a - b << endl;
    cout << "a-2 is " << a - 2 << endl;
    cout << "a*b is " << a * b << endl;
    cout << "2*a is " << 2 * a << endl;

    Complex c = b;
    cout << "b==c is " << (b == c) << endl;
    cout << "b!=c is " << (b != c) << endl;
    cout << "a==c is " << (a == c) << endl;

    Complex d;
    cout << "Enter a complex number:" << endl;
    cin >> d;
    cout << "d is " << d << endl;
}