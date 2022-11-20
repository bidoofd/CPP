#ifndef DISTTOLINE_H
#define DISTTOLINE_H
#include <math.h>

using namespace std;

class DistToLine {  
	private:
		static double a;
        static double b;
        static double c;
	public:
		static double getDistance(double x, double y);
        static void setA(double vA);
        static void setB(double vB);
        static void setC(double vC);
};

#endif
