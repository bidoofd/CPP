#include "DistToLine.h"
#include <iostream>
using namespace std;

double DistToLine::a=0;
double DistToLine::b=0;
double DistToLine::c=0;

int main()
{
    double vA,vB,vC,vX,vY;
    cout << "Enter the a value for the line: " << endl;
    cin >> vA;
    DistToLine::setA(vA);
    cout << "Enter the b value for the line: " << endl;
    cin >> vB;
    DistToLine::setA(vB);
    cout << "Enter the c value for the line: " << endl;
    cin >> vC;
    DistToLine::setA(vC);
    cout << "Enter the x0 coordinate for the point: " << endl;
    cin >> vX;
    cout << "Enter the y0 coordinate for the point: "<< endl;
    cin >> vY;

    cout << "Distance from the point to the line: " << DistToLine::getDistance(vX, vY) << endl;;

    system("pause");
}