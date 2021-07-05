#include "shape.h"
#include "CSphere.h"
#include "CCube.h"
#include <iostream>
int main()
{
    CCube a_cude(4.0,5.0,6.0);
    CSphere c_sphere(7.9);
    CStereoShape* p;
    p = &a_cude;
    p->show();
    p = &c_sphere;
    p->show();
    std::cout<<p->GetNumOfObject()<<" objects are created."<<endl;
    return 0;
}