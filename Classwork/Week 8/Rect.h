#ifndef RECT_H
#define RECT_H
#include "Shape.h"
#include <string>
using namespace std;

class Rect : public Shape
{
private:
    double width;
    double length;
	string name;

public:
    Rect(double width, double length, string name);
    double getWidth();
    double getLength();
	double getArea();
	string getName();	
};

#endif