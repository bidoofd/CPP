#include "Circle.h"
#include "Rect.h" 

#include <iostream>
#include <string>
using namespace std;

 
int main(){
	
 
    const int MAX = 2;	
	Shape *aShape[MAX];  // creating an array of 2 pointers where each element points to Shape class 

	// Step 1) create a Circle object
	// Step 2) create a Rect object

	Rect r1(2,2, "Rectangle");
	Circle c1(2, "Circle");

	
    // Step 3) save the address of the Circle object into the first element of the array
    // Step 4) save the address of the Rect object into the second element of the array

	aShape[0] = &c1;
	aShape[1] = &r1;
	
	// Step 5) iterate over the array and print the object name and area using aShape pointer (polymorphism) 

	//cout << "Name: "  << aShape[0]->getName() << endl;

	for(int a = 0; a < MAX; a++)
	{
		cout << "Name: " << aShape[a]->getName() << "\tArea: " << aShape[a]->getArea() << endl;
	}
}