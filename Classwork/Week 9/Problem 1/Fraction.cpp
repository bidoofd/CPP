#include "Fraction.h"


Fraction::Fraction(int num, int den)
{
	this->num = num;
	this->den = den;
} 

Fraction::Fraction(int num)
{
	this->num = num;
	den = 1;
} 

double Fraction::getFraction()
{
	return (double) num/den; // return the real value of the fraction
}
// note: this function is not a member function!, it was declared friend in the .h file
Fraction operator+(const Fraction &f1, const Fraction &f2)
{
	// use the Fraction constructor and operator*(int, int)
	// we can access num and den directly because this is a friend function
	
	return Fraction (((f1.num * f2.den) + (f1.den * f2.num)), (f1.den * f2.den));
}