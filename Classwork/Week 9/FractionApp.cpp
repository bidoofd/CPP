#include "Fraction.h" 
#include <iostream>
using namespace std; 
 
int main(){
	
	Fraction Frct1(5,8);
	Fraction Frct2(1,9);
	Fraction Frct3(Frct1 + Frct2 );  // the operator * is overloaded
	cout << "The addition of " << Frct1.getFraction() << " and " << 
	                                    Frct2.getFraction() << " is "  << 
										Frct3.getFraction() << "\n";

	return 0;	
}