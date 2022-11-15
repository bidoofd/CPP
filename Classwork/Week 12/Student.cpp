#include "Student.h"
#include <iostream>

using namespace std;
 
Student::Student() {
   numOfStudents = numOfStudents + 1;
}
void Student::setID(string stdID) {
	id = stdID;
}
void Student::setName(string stdName) {
	name = stdName;
}
string Student::getID() {
	return id ;
}
string Student::getName() {
	return name;
}

Student::~Student() {
   numOfStudents = numOfStudents - 1;
}

int Student::studentCount()
{
	return numOfStudents;
}

