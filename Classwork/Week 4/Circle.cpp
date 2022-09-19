#include "Circle.h"

// Circle constructor
Circle::Circle(double r, string n, string c)
{
    radius = r;
	name = n;
	color = c;
}

double Circle::getRadius()
{
    return radius;
}

string Circle::getName()
{
	return name;
}

string Circle::getColor()
{
	return color;
}

double Circle::getArea()
{
    return pow(radius,2) * M_PI;  // formula to compute circle area
}

double Circle::getPerimeter()
{
	return (2 * M_PI * radius);
}