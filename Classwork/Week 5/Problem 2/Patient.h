#ifndef PATIENT_H
#define PATIENT_H
#include "MedHistory.h"
#include <string>
using namespace std;

class Patient
{
    private:
        string name;
        int age;
        MedHistory *medHis;
    public:
        Patient();
        Patient(string n, int a);
        string getName();
        int getAge();
        void printInfo();
        void recInfo(string reason, string date);
};

#endif