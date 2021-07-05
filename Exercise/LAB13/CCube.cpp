#include <iostream>
#include "CCube.h"

using namespace std;

CCube::CCube(double length,double width,double height)
{
    this->length = length;
    this->width = width;
    this->height = height;
}

CCube::CCube(CCube& other)
{
    length = other.length;
    width = other.width;
    height = other.height;
}

CCube::CCube() : length(0.0), width(0.0), height(0.0){}

double CCube::GetArea()
{
    return (2*length*width+2*length*height+2*width*height);
}

double CCube::GetVolume()
{
    return length*width*height;
}

void CCube::show()
{
    cout<<"Cube length: "<<length<<", width: "<<width<<", height: "<<height<<endl;
    cout<<"Cube area: "<<GetArea()<<", volume: "<<GetVolume()<<endl;
}