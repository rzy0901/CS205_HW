#include "number.h"
#include <iostream>
Number::Number():num(0)
{
}
Number::Number(int n) : num(n)
{
}
Number Number::operator ++(int){
    this->num++;
    return Number(this->num-1);
}
Number Number::operator --(int){
    this->num--;
    return Number(this->num+1);
}
Number Number::operator ++(){
    this->num++;
    return Number(this->num);
}
Number Number::operator --(){
    this-num--;
    return Number(this->num);
}
std::ostream& operator << (std::ostream &os, Number& other)
{
    os << other.num;
    return os;
}