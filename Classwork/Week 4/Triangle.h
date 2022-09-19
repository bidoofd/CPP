#ifndef TRIANGLE_H   // condition the definition to prevent multiple inclusion
#define TRIANGLE_H

#include <math.h>
#include "Shape.h"
#include <string>
using namespace std;

class Triangle : public Shape   // inherit from shape class the following 
							  // attribute name & methods getArea() and getName()
{
private:
	
    double base;
    double height;
    double side1;
    double side2;

public:
    Triangle(double b, string n, string c, double h, double s1, double s2);
    double getBase();
    double getHeight();
    double getSide1();
    double getSide2();
	double getArea();   // promise to override the inherited method
	string getName();	// promise to override the inherited method
	string getColor();	// promise to override the inherited method
	double getPerimeter();
};

#endif