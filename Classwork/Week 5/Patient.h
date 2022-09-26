#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include "Doctor.h"

using namespace std;

class Patient : public Doctor
{
    private:
        string name;
        int age;
        string date;
    public:
        Patient(string n, int a, string d);
        string getName();
        int getAge();
        string getDate();
};

#endif