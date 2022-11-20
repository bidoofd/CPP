#include "DistToLine.h"
#include <iostream>
#include <stdlib.h>

using namespace std;
 
double DistToLine::getDistance(double x, double y)
{
    double numerator = (abs((a*x) + (b*y) + c));
    double denominator = (sqrt(pow(a,2) + pow(b,2)));
    return (numerator / denominator);
}

void DistToLine::setA(double vA)
{
    a = vA;
}

void DistToLine::setB(double vB)
{
    b = vB;
}

void DistToLine::setC(double vC)
{
    c = vC;
}
