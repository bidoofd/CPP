/*  Given the following problem of the RMU population.

    A person at RMU has a name and address and can be either student, staff, or faculty. 

    A student usually has a GPA and follows a major where a faculty has an office number and a rank. Finally, the staff has a job description and a grade. 

    Any person can show his record. */

#include "Person.h" 
#include "Student.h"
#include "Staff.h"
#include "Faculty.h"

#include <iostream>
#include <string>
using namespace std;

 
int main(){ 
    double gpa, offNum;
	string name, address, major, grade, jobDesc, rank;
	
    cout << "Enter the name of the student: ";
    cin >> name;
    cout << "Enter the address of the student: ";
    cin >> address;
    cout << "Enter GPA of student: ";
	cin >> gpa;
    cout << "Enter Major of student:  ";
	cin >> major;
	
	Student s1(gpa, major, name, address);
    cout << s1.getName() << " has the gpa " << s1.getGPA() << ", majoring in " << s1.getMajor() << ", and has the address " << s1.getAddress() << "." << endl;

    cout << "Enter the name of the staff: ";
    cin >> name;
    cout << "Enter the address of the staff: ";
    cin >> address;
    cout << "Enter the job description of the staff: ";
    cin >> jobDesc;
    cout << "Enter the grade of the staff: ";
    cin >> grade;

    Staff st1(jobDesc, grade, name, address);
    cout << st1.getName() << " has the job description " << st1.getJobDesc() << ", has the grade " << st1.getGrade() << ", and has the address " << st1.getAddress() << "." << endl;

    cout <<"Enter the name of the faculty: ";
    cin >> name;
    cout << "Enter the address of the faculty: ";
    cin >> address;
    cout << "Enter the office number: ";
    cin >> offNum;
    cout << "Enter rank of faculty: ";
    cin >> rank;

    Faculty f1(offNum, rank, name, address);
    cout << f1.getName() << " has the rank " << f1.getRank() << ", has the office number " << f1.getOffNum() << ", and has the address " << f1.getAddress() << "." << endl;
}
