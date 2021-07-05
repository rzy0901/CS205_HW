#include <iostream>

class Complex {
private:
    double imag;
    double real;
public:
    Complex();
    Complex(double re, double im);


    Complex operator+(const Complex& other) const;
    Complex operator+(double real) const;
    friend Complex operator+(double real, const Complex& other);

    Complex operator~() const;

    Complex operator-(const Complex& other) const;
    Complex operator- (double real) const;

    Complex operator*(const Complex& other) const;
    friend Complex operator*(double real, const Complex& other);

    bool operator== (const Complex& other) const;
    bool operator!= (const Complex& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Complex& other);
    friend std::istream &operator>>(std::istream &is, Complex &other);

};
