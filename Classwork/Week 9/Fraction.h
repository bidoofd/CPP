#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>

using namespace std;
 
class Fraction
{
	private:
		int num;
		int den;
		
	public:
		Fraction(int num, int den);
		Fraction(int num); // constructor overload
		double getFraction();

// friend keyword allows non member function to access private members 		
		friend Fraction operator+(const Fraction &f1, const Fraction &f2);
};
#endif