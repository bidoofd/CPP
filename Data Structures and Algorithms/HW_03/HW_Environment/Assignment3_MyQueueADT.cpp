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
    // Variables
    //  - size: creates size of list for ADT class
    //  - index: inputted index value
    //  - value: inputted user value
    //  - flag: flag for errors
    //  - choice: Menu selection
    //  - name: name to create class
    int size, index, value, flag;
    int choice = 1;

    string name, line;
    
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


    // Creates size of list
    cout << "Enter the size of the array" << endl;
    cin >> size;

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

    while(choice != 8)
    {
        // Menu Options
        cout << "Enter which option you would like to choose by number: \n" << endl;
        cout << "1. queueSize" << endl;
        cout << "2. emptyFlag" << endl;
        cout << "3. fullFlag" << endl;
        cout << "4. firstInQueue" << endl;
        cout << "5. enqueue" << endl;
        cout << "6. dequeue" << endl;

        cin >> choice;

        cout << "\n\n" << endl;
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
        }
        else if(choice == 2)
        {
            flag = mQA.emptyFlag();
            if(flag == 1)
            {
                cout << "The queue is empty." << endl;
            }
            else if(flag == 0)
            {
                cout << "The queue is not empty." << endl;
            }
        }
        else if(choice == 3)
        {
            flag = mQA.fullFlag();
            if(flag == 1)
            {
                cout << "The queue is full." << endl;
            }
            else if(flag == 0)
            {
                cout << "The queue is not empty" << endl;
            }
        }
        else if(choice == 4)
        {
            flag = mQA.firstInQ();
            if(flag != -1)
            {
                cout << "The value at the beginning of the queue is: " << flag << "." << endl;
            }
            else if(flag == -1)
            {
                cout << "There is not element at the beginning of the queue." << endl;
                cout << "The queue is empty." << endl;
            }
        }

    }

    system("pause");
}