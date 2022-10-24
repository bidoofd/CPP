#include "Point.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{

    //Creates Points
    Point origin;
    Point pt1(0,0);
    Point pt2(1,1);

    //Stores point information in variables
    int p1x = pt1.getX();
    int p1y = pt1.getY();
    int p2x = pt2.getX();
    int p2y = pt2.getY();
    int ox = origin.getX();
    int oy = origin.getY();
    bool flag = false;

    //Prints out information regarding points
    cout << "Are thw two points equal?" << endl;
    cout << "Point1: " << "(" << p1x << ", " << p1y << ")" << endl;
    cout << "Point2: " << "(" << p2x << ", " << p2y << ")" << endl;

    if(p1x == p2x && p1y == p2y)
    {
        cout << "The two points are equal." << endl;
    }
    else
    {
        cout << "The two points are not equal." << endl;
    }

    flag = origin.isOrigin();

    cout << "The x coordinate of point 1 is: " << p1x << "." << endl;
    cout << "The y coordinate of point 1 is: " << p2x << "." << endl;
    cout << "Oirigin: " << "(" << ox << ", " << oy << ")" << endl;
    cout << "Is point 1 at the origin?: " << flag << endl;
}