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
    string objectName, fileName, arrName;
    int choice = 1;
    cout << "Enter the name of myUtilityClass object." << endl;
    getline(cin, objectName);
    myUtilityClass mUC(objectName);
    
    while(choice != 4)
    {
        cout << "Enter which option you would like to choose: " << endl;
        cout << "1. Read File" << endl;
        cout << "2. Print Arrays" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;
        if(choice == 1)
        {
            cout << "Enter the filepath of your text file: " << endl;
            cin.ignore();
            getline(cin, fileName);
            cout << "Enter the name of your array" << endl;
            cin.ignore(cin.rdbuf()->in_avail()); //clears buffer from escape character of \n from getline previously
            getline(cin, arrName);
            //Users/trando/Desktop/coding/c++/Data Structures and Algorithms/abcdef.txt
            if(mUC.readFileInt(fileName, arrName) != -1)
            {
                cout << "Success! Amount of numbers in file is: " << mUC.readFileInt(fileName, arrName) << "." << endl;
            }
            else if(mUC.readFileInt(fileName, arrName) == -1)
            {
                cout << "Unable to read file." << endl;
            }
        }
        else if(choice == 2)
        {
            mUC.displayArray();
        }
    }


    /*string fileName, arrName;
    cout << "Enter the filepath of your text file: " << endl;
    cin.ignore();
    getline(cin, fileName);
    cout << "Enter the name of your array" << endl;
    cin.ignore(cin.rdbuf()->in_avail()); //clears buffer from escape character of \n from getline previously
    getline(cin, arrName);
    mUC.readFileInt(fileName, arrName);
    ///Users/trando/Desktop/coding/c++/Data Strucures and Algorithms/abcdef.txt
    if(mUC.readFileInt(fileName, arrName) != -1)
    {
        cout << "Success! Amount of numbers in file is: " << mUC.readFileInt(fileName, arrName) << "." << endl;
    }
    else if(mUC.readFileInt(fileName, arrName) == -1)
    {
        cout << "Unable to read file." << endl;
    }*/
}