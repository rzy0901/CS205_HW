#ifndef SHAPE_CSphere_H
#define SHAPE_CSphere_H

#include "shape.h"

class CSphere : public CStereoShape
{
private:
    double radius;
public:
    CSphere();
    CSphere(CSphere& other);
    CSphere(double radius);
    double GetArea();
    double GetVolume();
    void show();
};
#endif