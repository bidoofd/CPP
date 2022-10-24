#include "Circle.h"

// Circle constructor
Circle::Circle(double radius, string name)
{
    this->radius = radius;
	this->name = name;
}

// Circle member function
double Circle::getRadius()
{
    return radius;
}

string Circle::getName()
{
	return name;
}

double Circle::getArea()
{
    return pow(radius,2) * M_PI;
}