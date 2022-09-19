#include "Rect.h"

// Rect constructor
Rect::Rect(double w, double l, string n, string c)
{
    width = w;
	length = l;
	name = n;
	color = c;
}

double Rect::getWidth()
{
    return width;  
}

string Rect::getName()
{
	return name;
}

string Rect::getColor()
{
	return color;
}

double Rect::getLength()
{
    return length;
}

double Rect::getArea()
{
    return (width + length) * 2;  // the formula to compute rectangle area
}

double Rect::getPerimeter()
{
	return (2 * length) + (2 * width);
}