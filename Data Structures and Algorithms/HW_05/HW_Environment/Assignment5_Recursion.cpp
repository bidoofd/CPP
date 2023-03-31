// Course #: ENGR-3440-A
// Semester: Spring 2023
// Name: Jason Tran Do
// Assignment #: 5. Recursion

// Note that the use of cin and getline are being used differently
//  - cin is used for ints and number values
//  - getline is being used for strings with spaces

#include <iostream>
#include <fstream>
#include <string>
#include "Recursion.h"

using namespace std;

//checks to see if a string is fully a number or not
//sources from: https://stackoverflow.com/a/4654718
bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int main()
{
    // Variables (int)
    //  - size: creates size of queue for ADT class
    //  - index: inputted index value
    //  - value: inputted user value
    //  - flag: flag for errors
    //  - choice: Menu selection

    // Variables (string)
    //  - name: name to create class
    //  - line: used to read string and changes for input file
    //  - stringSize: size of the array in string form
    //  - stringChoice: choice num value in the menu in string form
    //  - stringValue: num value in string form
    //  - recFile: start of file path

    // Variables (bool)
    // boolFlag: loop flag to check to see if input is a num

    int size, index, value, flag;
    int choice = 1;

    string name, line, stringSize, stringChoice, stringValue;

    bool boolFlag = true;
    
    string recFile = "./";

    //Enter filepath for the output file to record
    cout << "Enter the filename for output file: " << endl;
    getline(cin, line);
    recFile.append(line + ".txt");
    ofstream inFile(recFile);

    //clears contents of recording output file
    inFile.open(recFile, ios::trunc);
    inFile.close();

    cout << R"(                     .__.                                 ._. 
    __  _  __  ____  |  |    ____   ____    _____    ____ | | 
    \ \/ \/ /_/ __ \ |  |  _/ ___\ /  _ \  /     \ _/ __ \| | 
     \     / \  ___/ |  |__\  \___(  <_> )|  Y Y  \\  ___/ \| 
      \/\_/   \___  >|____/ \___  >\____/ |__|_|  / \___  >__ 
                  \/            \/      \_/     \/      \/ \/)" << endl;

    cout << "\n\n" << endl;


    // Creates size of list and loops until int is inputted
    while(boolFlag)
    {
        //asks user for input
        cout << "Enter the size of the stack" << endl;
        getline(cin, stringSize);
        // uses is_number function to see if inputted value is a num
        if(is_number(stringSize) == false)
        {
            cout << "Not a valid size." << endl;
            //if it isnt, then have the user re enter value until num
        }
        else if(is_number(stringSize) == true)
        {
            //convert string to int and end loop
            size = stoi(stringSize);
            //if to check if the value is is greater than 0 for invalid size
            if(size > 0)
            {
                cout << "Not a valid size." << endl;
            }
            else
            {
                boolFlag = false;
            }
        }
    }

    // Entering name to create object
    cout << "Enter the name of recursion object" << endl;
    cin.ignore(); //ignores newline character from line 52 "cin >> size"
    getline(cin, name);

    // Creates object
    recursion mSA(name, size);

    inFile.open(recFile);

    // Objects writes to recording file
    mSA.writeOutput(inFile, R"(                     .__.                                 ._. 
    __  _  __  ____  |  |    ____   ____    _____    ____ | | 
    \ \/ \/ /_/ __ \ |  |  _/ ___\ /  _ \  /     \ _/ __ \| | 
     \     / \  ___/ |  |__\  \___(  <_> )|  Y Y  \\  ___/ \| 
      \/\_/   \___  >|____/ \___  >\____/ |__|_|  / \___  >__ 
                  \/            \/      \_/     \/      \/ \/)");

    mSA.writeOutput(inFile, "Enter the size of the array");
    mSA.writeOutput(inFile, to_string(size));
    mSA.writeOutput(inFile, "Enter the name of myQueueADT object");
    mSA.writeOutput(inFile, name);
}