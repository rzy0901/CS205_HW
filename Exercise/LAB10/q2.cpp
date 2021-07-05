#include <iostream>

using namespace std;

class Rectangule
{
public:
    double width;
    double height;

public:
    Rectangule()
    {
        width = 0;
        height = 0;
    }
    Rectangule(double width, double height)
    {
        this->width = width;
        this->height = height;
    }
    double getArea()
    {
        return width*height;
    }
    double getPerimeter()
    {
        return 2*width+2*height;
    }
    void display()
    {
        cout << "Width: \t" << width << endl;
        cout << "Height: \t" << height << endl;
        cout << "Area: \t" << getArea() << endl;
        cout << "Perimeter: \t" << getPerimeter() << endl;
    }
};

int main()
{
    cout << "Rectangle 1\n--------------"<<endl;
    Rectangule r1(4,40);
    r1.display();
    cout << "Rectangle 2\n--------------"<<endl;
    Rectangule r2(3.5,35.9);
    r2.display();
    return 0;
}