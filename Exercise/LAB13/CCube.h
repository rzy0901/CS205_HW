#ifndef SHAPE_CCube_H
#define SHAPE_CCube_H

#include "shape.h"

class CCube : public CStereoShape
{
private:
    double length;
    double width;
    double height;
public:
    CCube(double length,double width,double height);
    CCube(CCube& other);
    CCube();

    double GetArea();
    double GetVolume();
    void show();
};
#endif