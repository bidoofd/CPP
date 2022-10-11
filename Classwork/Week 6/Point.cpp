#include "Point.h"
#include <iostream>

//Default origin point
Point::Point()
{
    x = 0;
    y = 0;
}

//Point creation
Point::Point(int vX, int vY)
{
    x = vX;
    y = vY;
}

//Point getX method
int Point::getX()
{
    return x;
}

//Point getY method
int Point::getY()
{
    return y;
}

//Point isOrigin method
bool Point::isOrigin()
{
    if(getX() == 0 && getY() == 0)
    {
        return true;
    }
    else{
        return false;
    }
}

