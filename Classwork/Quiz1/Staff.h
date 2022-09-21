#ifndef STAFF_H
#define STAFF_H
#include "Person.h"
#include <string>
using namespace std;

class Staff : public Person
{
private:
	
    string jobDesc;
    string grade;

public:
    Staff(string j, string g, string n, string a);
    string getJobDesc();
    string getGrade();
    string getName();
    string getAddress();
};

#endif