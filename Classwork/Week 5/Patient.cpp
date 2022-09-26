#include "Patient.h"
#include <iostream>
#include <string>
using namespace std;


Patient::Patient(string name, int age, string date)
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