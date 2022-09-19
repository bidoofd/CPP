#ifndef RECT_H // condition the definition to prevent multiple inclusion
#define RECT_H
#include "Shape.h"
#include <string>
using namespace std;

class Rect : public Shape  // inherit from shape class the following 
						  // attribute name & methods getArea() and getName()
{
private:

    double width;
    double length;

public:
    Rect(double w, double l, string n, string c);
    double getWidth();
    double getLength();
	double getArea();	// promise to override the inherited method
	string getName();	// promise to override the inherited method
	string getColor();	// promise to override the inherited method
    double getPerimeter();
};

#endif