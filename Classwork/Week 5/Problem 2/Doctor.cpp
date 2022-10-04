#include "Doctor.h"
#include <iostream>
#include <string>

using namespace std;

Doctor::Doctor(string docN)
{
    docName = docN;
    aPatient = NULL;
}

void Doctor::viewPatient(Patient *p)
{
    aPatient = p;
}

void Doctor::setPatient()
{
    string r,d;

    cout << "Enter the reason: " << endl;
    cin >> r;
    cout << "Enter the date: " << endl;
    cin >> d;
    aPatient->recInfo(r,d);
}