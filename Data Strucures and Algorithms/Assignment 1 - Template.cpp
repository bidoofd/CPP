// Course #: ENGR-3440-A
// Semester: Spring 2023
// Name: Jason Tran Do
// Assignment #: 1. Preparations


#include <iostream>
#include <fstream>
#include <string>
#include "myUtilityClass.h"

int main()
{
    myUtilityClass mUC("1");
    mUC.readFile("/Users/trando/Desktop/coding/c++/Data Strucures and Algorithms/abcdef.txt");
    mUC.displayArray();
}