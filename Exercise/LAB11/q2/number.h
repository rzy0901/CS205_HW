#include <iostream>
class Number
{
private:
    int num;
public:
    Number();
    Number(int n);
    Number operator ++(int);
    Number operator ++();

    Number operator --(int);
    Number operator --();

    friend std::ostream &operator << (std::ostream &os, Number& other);
};