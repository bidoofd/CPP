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

    // Entering name to create object
    cout << "Enter the name of recursion object" << endl;
    cin.ignore(); //ignores newline character from line 52 "cin >> size"
    getline(cin, name);

    // Creates object
    recursion rec(name);

    inFile.open(recFile);

    // Objects writes to recording file
    rec.writeOutput(inFile, R"(                     .__.                                 ._. 
    __  _  __  ____  |  |    ____   ____    _____    ____ | | 
    \ \/ \/ /_/ __ \ |  |  _/ ___\ /  _ \  /     \ _/ __ \| | 
     \     / \  ___/ |  |__\  \___(  <_> )|  Y Y  \\  ___/ \| 
      \/\_/   \___  >|____/ \___  >\____/ |__|_|  / \___  >__ 
                  \/            \/      \_/     \/      \/ \/)");

    rec.writeOutput(inFile, "Enter the name of myQueueADT object");
    rec.writeOutput(inFile, name);

    while(choice != 4)
    {
        boolFlag = true;
        rec.resetInstructions();
        // Menu Options
        cout << "Enter which option you would like to choose by number: \n" << endl;
        cout << "1. reverseIterative" << endl;
        cout << "2. reverseRrecursion" << endl;
        cout << "3. reverseSimulatedRecursion" << endl;
        cout << "4. To Exit." << endl;

        while(boolFlag)
        {
            getline(cin, stringChoice);
            if(is_number(stringChoice) == false)
            {
                cout << "Not a valid choice." << endl;
                rec.writeOutput(inFile, "Not a valid choice.");
            }
            else if(is_number(stringChoice) == true)
            {
                choice = stoi(stringChoice);
                boolFlag = false;
            }
        }

        boolFlag = true;

        cout << "\n\n" << endl;
        rec.writeOutput(inFile, "\n\n");
        rec.writeOutput(inFile, "Enter which option you would like to choose by number: \n");
        rec.writeOutput(inFile, "1. reverseIterative");
        rec.writeOutput(inFile, "2. reverseRrecursion");
        rec.writeOutput(inFile, "3. reverseSimulatedRecursion");
        rec.writeOutput(inFile, "4. To Exit.");
        rec.writeOutput(inFile, to_string(choice));


        //The if menu and print operations of flags
        // -Flag variable is being used to determine the operation used
        if(choice == 1)
        {
            cout << "Enter the filename for the file to print: " << endl;
            getline(cin, line);
            rec.reverseIterative(line);
        }
        else if(choice == 2)
        {
            cout << "Enter the filename for the file to print: " << endl;
            getline(cin, line);
            rec.reverseIterative(line);
        }
    }
    system("pause");
}