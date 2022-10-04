#include "Doctor.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    Doctor doct("Dr. Mo");
    Patient list[10];
    string name;
    int age, count;

    cout << "enter patient name: " ;
	cin >> name;
	cout << "enter patient age: " ;
	cin >> age;	

	list[0] = Patient(name, age);

	doct.viewPatient(&list[0]);
	doct.setPatient();
	list[0].printInfo();
}