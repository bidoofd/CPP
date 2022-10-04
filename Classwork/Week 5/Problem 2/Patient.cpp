#include "Patient.h"
#include <iostream>

Patient::Patient()
{

}

Patient::Patient(string n, int a)
{
    name = n;
    age = a;
}

string Patient::getName()
{
    return name;
}

int Patient::getAge()
{
    return age;
}

void Patient::printInfo()
{
    cout << "Name: " << getName() << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Reason: " << medHis->getReason() << endl;
    cout << "Date: " << medHis->getDate() << endl;
    cout << "Appt #: " << medHis->getApptNum() << endl;
}

void Patient::recInfo(string reason, string date)
{
    medHis = new MedHistory(reason, date);
    medHis->incApptNum();
}