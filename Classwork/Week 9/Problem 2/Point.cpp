#include "Point.h"
#include <iostream>
#include <math.h>

Point::Point()
{
    x = 0;
    y = 0;
}

Point::Point(double value)
{
    value = 0;
}

Point::Point(double vX, double vY)
{
    x = vX;
    y = vY;
}

double Point::getX()
{
    return x;
}

double Point::getY()
{
    return y;
}

double Point::getDistance(int x1, int x2, int y1, int y2)
{
    double distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    return distance;
}

Point operator+(const Point &p1, const Point&p2)
{
	return Point((p1.x) + p2.x, (p1.y + p2.y));
}