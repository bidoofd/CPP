#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include "MedHistory.h"

using namespace std;

class Patient
{
    private:
        string name;
        int age;
        MedHistory *medHistory;
    public:
        Patient(string n, int a, string d);
        string getName();
        int getAge();
        string getDate();
};

#endif