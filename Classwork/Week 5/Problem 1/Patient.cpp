#include "Patient.h"
#include <iostream>
#include <string>
using namespace std;


Patient::Patient(string n, int a, string d)
{
    name = n;
    age = a;
    date = d;
}

string Patient::getName()
{
    return name;
}

int Patient::getAge()
{
    return age;
}

string Patient::getDate()
{
    return date;
}