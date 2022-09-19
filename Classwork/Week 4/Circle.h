#ifndef CIRCLE_H   // condition the definition to prevent multiple inclusion
#define CIRCLE_H

#include <math.h>
#include "Shape.h"
#include <string>
using namespace std;

class Circle : public Shape   // inherit from shape class the following 
							  // attribute name & methods getArea() and getName()
{
private:
	
    double radius;

public:
    Circle(double r, string n, string c);
    double getRadius();
	double getArea();   // promise to override the inherited method
	string getName();	// promise to override the inherited method
	string getColor();	// promise to override the inherited method
	double getPerimeter();
};

#endif