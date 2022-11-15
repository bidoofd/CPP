#include "Student.h"
#include <iostream>
using namespace std;

int Student::numOfStudents=0;

// add a private static data member to hold the count of students
// add a public static function that returns the count of students
// whenever you create a student object, you need to increment the count (Hint: constructor)
// whenever you delete a student object, you need to decrement the count (Hint: destructor)
// in the main application, you need to display the count of student each time you create a student object or delete one.  

int main()
{
	Student *std1  = new Student();
	int num = Student::studentCount();
	cout << "Student Count: " << num << endl;
	Student *std2 = new Student();
	num = Student::studentCount();
	cout << "Student Count: " << num << endl;
	std1->setID("R0123456");
	std1->setName("Ellie");
	cout << "Student " << std1->getName() << " has the id: " << std1->getID() << endl;


	std2->setID("R999999");
	std2->setName("Akmad");
	
	cout << "Student " << std2->getName() << " has the id: " << std2->getID() << endl;
	delete std1;
	delete std2;

	num = Student::studentCount();
	cout << "Student Count: " << num << endl;
	
	return 0;
}