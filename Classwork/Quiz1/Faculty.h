#ifndef FACULTY_H   // condition the definition to prevent multiple inclusion
#define FACULTY_H
#include "Person.h"
#include <string>
using namespace std;

class Faculty : public Person   // inherit from shape class the following 
							  // attribute name & methods getArea() and getName()
{
private:
	
    int offNum;
    string rank;

public:
    Faculty(int o, string r, string n, string a);
    int getOffNum();
    string getRank();
    string getName();
    string getAddress();
};

#endif