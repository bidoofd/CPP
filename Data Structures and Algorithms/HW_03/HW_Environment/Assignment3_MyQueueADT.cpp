// Course #: ENGR-3440-A
// Semester: Spring 2023
// Name: Jason Tran Do
// Assignment #: 3. Queue ADT

// Note that the use of cin and getline are being used differently
//  - cin is used for ints and number values
//  - getline is being used for strings with spaces

#include <iostream>
#include <fstream>
#include <string>
#include "myQueueADT.h"

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
        cout << "Enter the size of the array" << endl;
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
            boolFlag = false;
        }
    }

    // Entering name to create object
    cout << "Enter the name of myQueueADT object" << endl;
    cin.ignore(); //ignores newline character from line 52 "cin >> size"
    getline(cin, name);

    // Creates object
    myQueueADT mQA(name, size);

    inFile.open(recFile);

    mQA.writeOutput(inFile, R"(                     .__.                                 ._. 
    __  _  __  ____  |  |    ____   ____    _____    ____ | | 
    \ \/ \/ /_/ __ \ |  |  _/ ___\ /  _ \  /     \ _/ __ \| | 
     \     / \  ___/ |  |__\  \___(  <_> )|  Y Y  \\  ___/ \| 
      \/\_/   \___  >|____/ \___  >\____/ |__|_|  / \___  >__ 
                  \/            \/      \_/     \/      \/ \/)");

    mQA.writeOutput(inFile, "Enter the size of the array");
    mQA.writeOutput(inFile, to_string(size));
    mQA.writeOutput(inFile, "Enter the name of myQueueADT object");
    mQA.writeOutput(inFile, name);

    while(choice != 7)
    {
        boolFlag = true;
        mQA.resetInstructions();
        // Menu Options
        cout << "Enter which option you would like to choose by number: \n" << endl;
        cout << "1. queueSize" << endl;
        cout << "2. emptyFlag" << endl;
        cout << "3. fullFlag" << endl;
        cout << "4. firstInQueue" << endl;
        cout << "5. enqueue" << endl;
        cout << "6. dequeue" << endl;
        cout << "7. Exit" << endl;

        while(boolFlag)
        {
            getline(cin, stringChoice);
            if(is_number(stringChoice) == false)
            {
                cout << "Not a valid choice." << endl;
                mQA.writeOutput(inFile, "Not a valid choice.");
            }
            else if(is_number(stringChoice) == true)
            {
                choice = stoi(stringChoice);
                boolFlag = false;
            }
        }

        boolFlag = true;

        cout << "\n\n" << endl;
        mQA.writeOutput(inFile, "\n\n");
        mQA.writeOutput(inFile, "Enter which option you would like to choose by number: \n");
        mQA.writeOutput(inFile, "1. queueSize");
        mQA.writeOutput(inFile, "2. emptyFlag");
        mQA.writeOutput(inFile, "3. fullFlag");
        mQA.writeOutput(inFile, "4. firstInQueue");
        mQA.writeOutput(inFile, "5. enqueue");
        mQA.writeOutput(inFile, "6. dequeue");
        mQA.writeOutput(inFile, to_string(choice));

        if(choice == 1)
        {
            cout << "The MAX queue size is: " << mQA.qSize() << "." << endl;
            cout << "The number of instructions executed is " << mQA.getInstructions() << "." << endl;
            mQA.writeOutput(inFile, "The MAX queue size is: " + to_string(mQA.qSize()) + ".");
            mQA.writeOutput(inFile, "The number of instructions executed is " + to_string(mQA.getInstructions()) + ".");
        }
        else if(choice == 2)
        {
            flag = mQA.emptyFlag();
            if(flag == 1)
            {
                cout << "The queue is empty." << endl;
                mQA.writeOutput(inFile, "The queue is empty.");
            }
            else if(flag == false)
            {
                cout << "The queue is not empty." << endl;
                mQA.writeOutput(inFile, "The queue is not empty.");
            }
        }
        else if(choice == 3)
        {
            flag = mQA.fullFlag();
            if(flag == 1)
            {
                cout << "The queue is full." << endl;
                mQA.writeOutput(inFile, "The queue is full.");
            }
            else if(flag == false)
            {
                cout << "The queue is not full." << endl;
                mQA.writeOutput(inFile, "The queue is not full.");
            }
        }
        else if(choice == 4)
        {
            flag = mQA.firstInQ();
            cout << "The number of instructions executed is " << mQA.getInstructions() << "." << endl;
            mQA.writeOutput(inFile, "The number of instructions executed is " + to_string(mQA.getInstructions()) + ".");
            if(flag != -1)
            {
                cout << "The value at the beginning of the queue is: " << flag << "." << endl;
                mQA.writeOutput(inFile, "The value at the beginning of the queue is: " + to_string(flag) + ".");
            }
            else if(flag == -1)
            {
                cout << "There is not element at the beginning of the queue." << endl;
                cout << "The queue is empty." << endl;

                mQA.writeOutput(inFile, "There is not element at the beginning of the queue.");
                mQA.writeOutput(inFile, "The queue is empty.");
            }
        }
        else if(choice == 5)
        {
            cout << "Enter the number you want to add into the queue: " << endl;
            mQA.writeOutput(inFile, "Enter the number you want to add into the queue: ");
            while(boolFlag)
            {
                getline(cin, stringValue);
                if(is_number(stringValue) == false)
                {
                    cout << "Not a valid number." << endl;
                    mQA.writeOutput(inFile, "Not a valid number.");
            }
                else if(is_number(stringValue) == true)
                {
                    value = stoi(stringValue);
                    boolFlag = false;
                }
            }
            flag = mQA.enqueue(value);
            cout << "The number of instructions executed is " << mQA.getInstructions() << "." << endl;
            mQA.writeOutput(inFile, "The number of instructions executed is " + to_string(mQA.getInstructions()) + ".");
            if(flag == -1)
            {
                cout << "The queue is full." << endl;
                mQA.writeOutput(inFile, "The queue is full.");
            }
            else
            {
                cout << "The number inserted into the queue is: " << flag << "." << endl;
                mQA.writeOutput(inFile, "The number inserted into the queue is: " + to_string(flag) + ".");
            }
        }
        else if(choice == 6)
        {
            flag = mQA.dequeue();
            cout << "The number of instructions executed is " << mQA.getInstructions() << "." << endl;
            mQA.writeOutput(inFile, "The number of instructions executed is " + to_string(mQA.getInstructions()) + ".");
            if(flag == -1)
            {
                cout << "The queue is empty." << endl;
                mQA.writeOutput(inFile, "The queue is empty.");
            }
            else
            {
                cout << "The number dequeued from the queue is: " << flag << "." << endl;
                mQA.writeOutput(inFile, "The number dequeued from the queue is: " + to_string(flag) + ".");
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


    mQA.writeOutput(inFile, R"(   ____                     .______.                  ._. 
  / ___\  ____    ____    __| _/\_ |__  ___.__.  ____ | | 
 / /_/  >/  _ \  /  _ \  / __ |  | __ \<   |  |_/ __ \| | 
 \___  /(  <_> )(  <_> )/ /_/ |  | \_\ \\___  |\  ___/ \| 
/_____/  \____/  \____/ \____ |  |___  // ____| \___  >__ 
        \______________/     \/      \/ \/          \/ \/ 
                                                          )");
    system("pause");
}