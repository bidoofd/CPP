#include "Student.h"
#include <string>
#include <iostream>
using namespace std;

Student::Student(int g, string m, string n, string a)
{
    gpa = g;
    major = m;
    name = n;
    address = a;
}

int Student::getGPA()
{
    return gpa;
}

string Student::getName()
{
	return name;
}

string Student::getAddress()
{
	return address;
}

string Student::getMajor()
{
    return major;
}
