#include "Rect.h"

// Rect constructor
Rect::Rect(double width, double length, string name)
{
    this->width = width;
	this->length = length;
	this->name = name;
}

// Rect member function
double Rect::getWidth()
{
    return width;  
}


string Rect::getName()
{
	return name;
}

double Rect::getLength()
{
    return length;
}


double Rect::getArea()
{
    return (width + length) * 2;
}