#include "Staff.h"
#include <string>
#include <iostream>
using namespace std;

Staff::Staff(string j, string g, string n, string a)
{
    jobDesc = j;
    grade = g;
    name = n;
    address = a;
}

string Staff::getJobDesc()
{
    return jobDesc;
}

string Staff::getName()
{
	return name;
}

string Staff::getAddress()
{
	return address;
}

string Staff::getGrade()
{
    return grade;
}
