#include <iostream>
#include <cmath>
#include "CSphere.h"

using namespace std;

CSphere::CSphere() : radius(0.0){}
CSphere::CSphere(CSphere& other)
{
    radius = other.radius;
}
CSphere::CSphere(double radius)
{
    this->radius = radius;
}
double CSphere::GetArea()
{
    return 4*M_PI*radius*radius;
}
double CSphere::GetVolume()
{
    return 4.0/3*M_PI*pow(radius,3);
}
void CSphere::show()
{
    cout<<"CSphere raduis: "<<radius<<endl;
    cout<<"CSphere area: "<<GetArea()<<", volume: "<<GetVolume()<<endl;
}