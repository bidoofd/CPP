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
    //Variable names
    string objectName, fileName, arrName;
    int choice = 1;

    //Enter the name of an object just to use methods
    cout << "Enter the name of myUtilityClass object." << endl;
    getline(cin, objectName);
    myUtilityClass mUC(objectName);
    
    while(choice != 4)
    {
        //Menu
        cout << "Enter which option you would like to choose: " << endl;
        cout << "1. Read File" << endl;
        cout << "2. Print Arrays" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;
        if(choice == 1)
        {
            //Enter filepath name
            cout << "Enter the filepath of your text file: " << endl;
            cin.ignore();
            getline(cin, fileName);
            //Enter name of array (acts as key)
            cout << "Enter the name of your array" << endl;
            cin.ignore(cin.rdbuf()->in_avail()); //clears buffer from escape character of \n from getline previously

            //Filepath tesy comment below
            //Users/trando/Desktop/coding/c++/Data Structures and Algorithms/abcdef.txt

            getline(cin, arrName);
            //If statement to see if it can find a file
            if(mUC.findFile(fileName))
            {
                //if successful prints out number of lines in file
                cout << "Success! Amount of numbers in file is: " << mUC.readFileInt(fileName, arrName) << "." << endl;
            }
            else
            {
                //otherwise does not do anything
                cout << "Unable to read file." << endl;
            }
        }
        else if(choice == 2)
        {
            //displays array stored in hashmap
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