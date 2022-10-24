#ifndef CIRCLE_H
#define CIRCLE_H

#include <math.h>
#include "Shape.h"
#include <string>
using namespace std;

class Circle : public Shape
{
private:
	string name;
    double radius;

public:
    Circle(double radius, string name);
    double getRadius();
	double getArea();
	string getName();	
};

#endif