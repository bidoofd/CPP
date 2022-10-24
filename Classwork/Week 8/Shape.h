#ifndef SHAPE_H
#define SHAPE_H
#include <string>
using namespace std;

class Shape
{
	public: 
		virtual double getArea()=0; // pure virtual function, has no idea how to compute area
		virtual string getName()=0; // no idea what name should be returned, therefore pure vp
};

#endif