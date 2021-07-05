#include <iostream>
#include "complex.h"

Complex::Complex() : real(0), imag(0)
{
}
Complex::Complex(double re, double im) : real(re), imag(im)
{
}

Complex Complex::operator+(const Complex &other) const
{
    double result_real = this->real + other.real;
    double result_imag = this->imag + other.imag;
    return Complex(result_real, result_imag);
}
Complex Complex::operator+(double real) const
{
    double result_real = this->real + real;
    double result_imag = this->imag;
    return Complex(result_real, result_imag);
}
Complex operator+(double real, const Complex &other)
{
    double result_real = real + other.real;
    double result_imag = other.imag;
    return Complex(result_real, result_imag);
}

Complex Complex::operator~() const
{
    double result_real = this->real;
    double result_imag = -this->imag;
    return Complex(result_real, result_imag);
}

Complex Complex::operator-(const Complex &other) const
{
    double result_real = this->real - other.real;
    double result_imag = this->imag - other.imag;
    return Complex(result_real, result_imag);
}
Complex Complex::operator-(double real) const
{
    double result_real = this->real - real;
    double result_imag = this->imag;
    return Complex(result_real, result_imag);
}
Complex Complex::operator*(const Complex &other) const
{
    double result_real = this->real * other.real - this->imag * other.imag;
    double result_imag = this->real * other.imag + this->imag * other.real;
    return Complex(result_real, result_imag);
}
Complex operator*(double real, const Complex &other)
{
    double result_real = real * other.real;
    double result_imag = real * other.imag;
    return Complex(result_real, result_imag);
}
bool Complex::operator==(const Complex &other) const
{
    return this->real == other.real && this->imag == other.imag;
}
bool Complex::operator!=(const Complex &other) const
{
    return !(this->real == other.real && this->imag == other.imag);
}
std::ostream &operator<<(std::ostream &os, const Complex &other)
{
    if (other.imag > 0)
    {
        os << other.real << "+" << other.imag << "i";
    }
    else if (other.imag == 0)
    {
        os << other.real;
    }
    else
    {
        os << other.real << other.imag << "i";
    }
    return os;
}
std::istream &operator>>(std::istream &is, Complex &other)
{
    std::cout << "real:";
    is >> other.real;
    std::cout << "imaginary:";
    is >> other.imag;
    return is;
}