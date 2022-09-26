#ifndef SHAPE_H // condition the definition to prevent multiple inclusion
#define SHAPE_H
#include <string>
using namespace std;.

class Shape
{
	protected :
		string name;   // pass down this attribute to any derived class
		string color;
	public: 
	
	    double getArea(); // has no idea how to compute area, 
									// if no implementation, must use pure virtual function
	    string getName(); // Similarly, shape may have circle or rectangle name, 
		                            // no implementation and decision should be made at derived class
        string getColor();	

		double getPerimieter();						
};

#endif