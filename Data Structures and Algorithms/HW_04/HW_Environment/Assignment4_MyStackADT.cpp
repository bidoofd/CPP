// Course #: ENGR-3440-A
// Semester: Spring 2023
// Name: Jason Tran Do
// Assignment #: 4. Stack ADT

// Note that the use of cin and getline are being used differently
//  - cin is used for ints and number values
//  - getline is being used for strings with spaces

#include <iostream>
#include <fstream>
#include <string>
#include "myStackADT.h"

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
    cout << "Enter the name of myStackADT object" << endl;
    cin.ignore(); //ignores newline character from line 52 "cin >> size"
    getline(cin, name);

    // Creates object
    myStackADT mSA(name, size);

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

    while(choice != 6)
    {
        boolFlag = true;
        mSA.resetInstructions();
        // Menu Options
        cout << "Enter which option you would like to choose by number: \n" << endl;
        cout << "1. size" << endl;
        cout << "2. isEmpty" << endl;
        cout << "3. top" << endl;
        cout << "4. push" << endl;
        cout << "5. pop" << endl;
        cout << "6. To Exit." << endl;

        while(boolFlag)
        {
            getline(cin, stringChoice);
            if(is_number(stringChoice) == false)
            {
                cout << "Not a valid choice." << endl;
                mSA.writeOutput(inFile, "Not a valid choice.");
            }
            else if(is_number(stringChoice) == true)
            {
                choice = stoi(stringChoice);
                boolFlag = false;
            }
        }

        boolFlag = true;

        cout << "\n\n" << endl;
        mSA.writeOutput(inFile, "\n\n");
        mSA.writeOutput(inFile, "Enter which option you would like to choose by number: \n");
        mSA.writeOutput(inFile, "1. size");
        mSA.writeOutput(inFile, "2. isEmpty");
        mSA.writeOutput(inFile, "3. top");
        mSA.writeOutput(inFile, "4. push");
        mSA.writeOutput(inFile, "5. pop");
        mSA.writeOutput(inFile, to_string(choice));


        //The if menu and print operations of flags
        // -Flag variable is being used to determine the operation used
        if(choice == 1)
        {
            cout << "The MAX size of the stack is: " << mSA.size() << endl;
            cout << "The size of the CURRENT stack is: " << mSA.stackSize() << endl;
            cout << "The number of instructions executed is " << mSA.getInstructions() << "." << endl;

            mSA.writeOutput(inFile, "The size of the stack is: " + to_string(mSA.size()));
            mSA.writeOutput(inFile, "The size of the stack is: " + to_string(mSA.stackSize()));
            mSA.writeOutput(inFile, "The number of instructions executed is " + to_string(mSA.getInstructions()) + ".");
        }
        else if(choice == 2)
        {
            flag = mSA.isEmpty();
            if(flag == true)
            {
                cout << "The stack is empty." << endl;
                cout << "The number of instructions executed is " << mSA.getInstructions() << "." << endl;
                mSA.writeOutput(inFile, "The stack is empty.");
                mSA.writeOutput(inFile, "The number of instructions executed is " + to_string(mSA.getInstructions()) + ".");
            }
            else if(flag == false)
            {
                cout << "The stack is not empty." << endl;
                cout << "The number of instructions executed is " << mSA.getInstructions() << "." << endl;
                mSA.writeOutput(inFile, "The stack is not empty.");
                mSA.writeOutput(inFile, "The number of instructions executed is " + to_string(mSA.getInstructions()) + ".");
            }
        }
        else if(choice == 3)
        {
            flag = mSA.top();
            if(flag == -1)
            {
                cout << "The stack is empty." << endl;
                cout << "The number of instructions executed is " << mSA.getInstructions() << "." << endl;
                mSA.writeOutput(inFile, "The stack is empty.");
                mSA.writeOutput(inFile, "The number of instructions executed is " + to_string(mSA.getInstructions()) + ".");
            }
            else
            {
                cout << "The value at the top of the stack is: " << flag << endl;
                cout << "The number of instructions executed is " << mSA.getInstructions() << "." << endl;
                mSA.writeOutput(inFile, "The value at the top of the stack is: " + to_string(flag));
                mSA.writeOutput(inFile, "The number of instructions executed is " + to_string(mSA.getInstructions()) + ".");
            }
        }
        else if(choice == 4)
        {
            cout << "Enter the number you want to add into the stack: " << endl;
            mSA.writeOutput(inFile, "Enter the number you want to add into the stack: ");
            while(boolFlag)
            {
                getline(cin, stringValue);
                if(is_number(stringValue) == false)
                {
                    cout << "Not a valid number." << endl;
                    mSA.writeOutput(inFile, "Not a valid number.");
            }
                else if(is_number(stringValue) == true)
                {
                    value = stoi(stringValue);
                    boolFlag = false;
                }
            }
            flag = mSA.push(value);
            if(flag == 0)
            {
                cout << "The stack is full." << endl;
                cout << "The number of instructions executed is " << mSA.getInstructions() << "." << endl;
                mSA.writeOutput(inFile, "The stack is full.");
                mSA.writeOutput(inFile, "The number of instructions executed is " + to_string(mSA.getInstructions()) + ".");
            }
            else
            {
                cout << "Successfully pushed the value " << flag << " to the stack." << endl;
                cout << "The number of instructions executed is " << mSA.getInstructions() << "." << endl;
                mSA.writeOutput(inFile, "Successfully pushed the value " + to_string(flag) + " to the stack.");
                mSA.writeOutput(inFile, "The number of instructions executed is " + to_string(mSA.getInstructions()) + ".");
            }
        }
        else if(choice == 5)
        {
            flag = mSA.pop();
            if(flag == -1)
            {
                cout << "The stack is empty." << endl;
                cout << "The number of instructions executed is " << mSA.getInstructions() << "." << endl;
                mSA.writeOutput(inFile, "The stack is empty.");
                mSA.writeOutput(inFile, "The number of instructions executed is " + to_string(mSA.getInstructions()) + ".");
            }
            else
            {
                cout << "The value popped from the stack is: " << flag << "." << endl;
                cout << "The number of instructions executed is " << mSA.getInstructions() << "." << endl;
                mSA.writeOutput(inFile, "The value popped from the stack is: " + to_string(flag) + ".");
                mSA.writeOutput(inFile, "The number of instructions executed is " + to_string(mSA.getInstructions()) + ".");
            }
        }
    }

    cout << R"(   ____                     .______.                  ._. 
  / ___\  ____    ____    __| _/\_ |__  ___.__.  ____ | | 
 / /_/  >/  _ \  /  _ \  / __ |  | __ \<   |  |_/ __ \| | 
 \___  /(  <_> )(  <_> )/ /_/ |  | \_\ \\___  |\  ___/ \| 
/_____/  \____/  \____/ \____ |  |___  // ____| \___  >__ 
        \______________/     \/      \/ \/          \/ \/ 
                                                          )" << endl;


    mSA.writeOutput(inFile, R"(   ____                     .______.                  ._. 
  / ___\  ____    ____    __| _/\_ |__  ___.__.  ____ | | 
 / /_/  >/  _ \  /  _ \  / __ |  | __ \<   |  |_/ __ \| | 
 \___  /(  <_> )(  <_> )/ /_/ |  | \_\ \\___  |\  ___/ \| 
/_____/  \____/  \____/ \____ |  |___  // ____| \___  >__ 
        \______________/     \/      \/ \/          \/ \/ 
                                                          )");
    system("pause");
}