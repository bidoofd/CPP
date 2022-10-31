#include "Point.h"

#include <string>
#include <iostream>

using namespace std;

int main()
{
    Point *pointA = new Point(1,2);
    Point *pointB = new Point(2,3);
    Point *pointD = new Point(0);
    Point *pointC = new Point(*pointA + *pointB);

    double distance = pointD->getDistance(pointA->getX(), pointB->getX(), pointA->getY(), pointB->getY());

    cout << "Distance between Point A and Point C is: " << distance << endl;

    delete pointA;
    delete pointB;
}