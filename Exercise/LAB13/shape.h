#ifndef SHAPE_SHAPE_H
#define SHAPE_SHAPE_H

using namespace std;

class CStereoShape
{
private:
    static int numberOfObject;
public:
    CStereoShape(){numberOfObject++;}
    virtual double GetArea();
    virtual double GetVolume();
    virtual void show(){}
    virtual int GetNumOfObject(){return numberOfObject;}
};

#endif

