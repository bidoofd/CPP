#include "Triangle.h"
#include <iostream>
#include <string>
using namespace std;

// Circle constructor
Triangle::Triangle(double b, string n, string c, double h, double s1, double s2)
{
    base = b;
	name = n;
	color = c;
    height = h;
    side1 = s1;
    side2 = s2;
}

double Triangle::getBase()
{
    return base;
}

string Triangle::getName()
{
	return name;
}

string Triangle::getColor()
{
	return color;
}

double Triangle::getArea()
{
    return (0.5 * base * height);
}

double Triangle::getSide1()
{
    return side1;
}

double Triangle::getSide2()
{
    return side2;
}

double Triangle::getPerimeter()
{
    if((base + side1) < side2 || (base + side2) < side1)
    {
        return (base + side1 + side2);
    }
    else
    {
        cout << "Impossible perimeter" << endl;
        return 0;
    }
}