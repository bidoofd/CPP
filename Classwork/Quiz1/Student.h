#ifndef STUDENT_H   // condition the definition to prevent multiple inclusion
#define STUDENT_H
#include "Person.h"
#include <string>
using namespace std;

class Student : public Person
{
private:
	
    int gpa;
    string major;

public:
    Student(int g, string m, string n, string a);
    int getGPA();
    string getMajor();
    string getName();
    string getAddress();
};

#endif