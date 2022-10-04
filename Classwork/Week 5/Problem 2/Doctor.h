#ifndef DOCTOR_H
#define DOCTOR_H
#include "Patient.h"
#include <string>
#include <iostream>

class Doctor
{
    private:
        string docName;
        Patient *aPatient;
    public:
        Doctor(string docN);
        void viewPatient(Patient *p);
        void setPatient();
};

#endif