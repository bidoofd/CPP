#ifndef POINT_H
#define POINT_H

#include <math.h>
#include <string>
#include <iostream>

using namespace std;

class Point
{
    private:
        double x;
        double y;
        double value;
    public:
        Point();
        Point(double vValue);
        Point(double vX, double vY);
        double getX();
        double getY();
        double getDistance(int x1, int x2, int y1, int y2);

        friend Point operator+(const Point &p1, const Point &p2);
};

#endif