// Course #: ENGR-3440-A
// Semester: Spring 2023
// Name: Jason Tran Do
// Assignment #: 2. Queue ADT

// Note that the use of cin and getline are being used differently
//  - cin is used for ints and number values
//  - getline is being used for strings with spaces

#include <iostream>
#include <fstream>
#include <string>
#include "myQueueADT.h"

using namespace std;

int main()
{
    myQueueADT mQA("queue",10);
    cout << mQA.qSize() << endl;
    cout << mQA.emptyFlag() << endl;
    cout << mQA.fullFlag() << endl;

    system("pause");
}