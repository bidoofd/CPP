#ifndef _point_h
#define _point_h
#include <string>

/*
 * Class: Point
 * ------------
 * This class represents an x-y coordinate point on a two-dimensional
 * integer grid.  
 */
class Point {
public:
/*
 * Constructor: Point
 * Usage: Point origin;
 *        Point pt(x, y);
 * ----------------------
 * Creates a Point object with the specified x and y coordinates.  If the
 * coordinates are not supplied, the default constructor sets these fields
 * to 0.
 */
   Point();
   Point(int x, int y);

/*
 * Method: getX
 * Usage: int x = pt.getX();
 * -------------------------
 * Returns the x-coordinate of the point.
 */
   int getX() ;
/*
 * Method: getY
 * Usage: int y = pt.getY();
 * -------------------------
 * Returns the y-coordinate of the point.
 */
   int getY() ;
/*
 * Method: isOrigin
 * Usage: bool result = pt.isOrigin();
 * -------------------------
 * Returns true if x == y == 0, false otherwise
 */
   bool isOrigin() ;

/**********************************************************************/
private:
/* Instance variables */
   int x;                         /* The x-coordinate of the point */
   int y;                         /* The y-coordinate of the point */
};

#endif