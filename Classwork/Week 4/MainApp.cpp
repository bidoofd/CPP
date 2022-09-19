#include "Circle.h"
#include "Rect.h" 
#include "Triangle.h"

#include <iostream>
#include <string>
using namespace std;

 
int main(){ 
    double radius, width, length, base, side1, side2, height;
	string color;
    cout << "enter circle radius ";
	cin >> radius;
	
	Circle c1(radius, "Circle", "Red"); // creating circle object and initialize its data
    cout << "the area of a " << c1.getColor() << " " << c1.getName() << " is " << c1.getArea() << endl;
	
    cout << "enter rectangle width ";
	cin >> width;
    cout << "enter rectangle length ";
	cin >> length;
	
	Rect r1(width,length, "Rectangle", "Blue"); // creating rectangle object and initialize its data
    cout << "the area of a " << r1.getColor() << " " << r1.getName() << " is " << r1.getArea() << endl;
	

    cout << "Enter the base of the triangle: ";
    cin >> base;
    cout << "Enter the first side of a triangle: ";
    cin >> side1;
    cout << "Enter the second side of a triangle: ";
    cin >> side2;
    cout << "Enter the height of the triangle: ";
    cin >> height;

    Triangle t1(base, "Triangle", "Green", height, side1, side2);
    cout << "The area of " << t1.getColor() << " " << t1.getName() << " is " << t1.getArea() << endl;
    cout << "The perimeter of " << t1.getColor() << " " << t1.getName() << " is " << t1.getPerimeter() << endl;
}