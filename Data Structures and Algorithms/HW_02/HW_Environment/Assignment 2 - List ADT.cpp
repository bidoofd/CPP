// Course #: ENGR-3440-A
// Semester: Spring 2023
// Name: Jason Tran Do
// Assignment #: 2. List ADT

// Note that the use of cin and getline are being used differently
//  - cin is used for ints and number values
//  - getline is being used for strings with spaces

#include <iostream>
#include <fstream>
#include <string>
#include "myListADT.h"

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
    recFile.append(line);
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


    // Creates size of list
    cout << "Enter the size of the array" << endl;
    cin >> size;

    // Entering name to create object
    cout << "Enter the name of myListADT object" << endl;
    cin.ignore(); //ignores newline character from line 52 "cin >> size"
    getline(cin, name);

    myListADT mLA(name, size);

    inFile.open(recFile);

    mLA.writeOutput(inFile, R"(                     .__.                                 ._. 
    __  _  __  ____  |  |    ____   ____    _____    ____ | | 
    \ \/ \/ /_/ __ \ |  |  _/ ___\ /  _ \  /     \ _/ __ \| | 
     \     / \  ___/ |  |__\  \___(  <_> )|  Y Y  \\  ___/ \| 
      \/\_/   \___  >|____/ \___  >\____/ |__|_|  / \___  >__ 
                  \/            \/      \_/     \/      \/ \/)");

    mLA.writeOutput(inFile, "Enter the size of the array");
    mLA.writeOutput(inFile, to_string(size));
    mLA.writeOutput(inFile, "Enter the name of myListADT object");
    mLA.writeOutput(inFile, name);

    // While loop menu
    while(choice != 8)
    {
        // Menu Options
        cout << "Enter which option you would like to choose: " << endl;
        cout << "1. isEmpty" << endl;
        cout << "2. size" << endl;
        cout << "3. at" << endl;
        cout << "4. set" << endl;
        cout << "5. insert" << endl;
        cout << "6. erase" << endl;
        cout << "7. printList" << endl;
        cout << "8. Exit" << endl;
        cin >> choice;

        mLA.writeOutput(inFile, "Enter which option you would like to choose: ");
        mLA.writeOutput(inFile, "1. isEmpty");
        mLA.writeOutput(inFile, "2. size");
        mLA.writeOutput(inFile, "3. at");
        mLA.writeOutput(inFile, "4. set");
        mLA.writeOutput(inFile, "5. insert");
        mLA.writeOutput(inFile, "6. erase");
        mLA.writeOutput(inFile, "7. printList");
        mLA.writeOutput(inFile, "8. Exit");
        mLA.writeOutput(inFile, to_string(choice));

        if(choice == 1)
        {
            // Sets flag to result of function
            flag = mLA.isEmpty();

            // If function results in 1, list is empty
            if(flag == 1)
            {
                cout << "The list is empty." << endl;
                mLA.writeOutput(inFile, "The list is empty.");
            }
            // Otherwise list is not empty
            else if(flag == 0)
            {
                cout << "The list is not empty." << endl;
                mLA.writeOutput(inFile, "The list is not empty.");
            }
        }
        else if(choice == 2)
        {
            // Prints out the size of list BUT NOT MAX size
            cout << "The size of the list is: " << mLA.size() << endl;
            mLA.writeOutput(inFile, "The size of the list is: " + to_string(mLA.size()));
        }
        else if(choice == 3)
        {
            // Asks user for index
            cout << "Enter the index you want to see: " << endl;
            cin >> index;

            mLA.writeOutput(inFile, "Enter the index you want to see: ");
            mLA.writeOutput(inFile, to_string(index));

            flag = mLA.at(index);
            // If flag is -1 then index does not exist
            if(flag == -1)
            {
                cout << "Index does not exist." << endl;
                mLA.writeOutput(inFile, "Index does not exist.");
            }
            // Otherwise displays the value at inputted index
            else
            {
                cout << "Value at the index " << index << " is " << flag << "." << endl;
                mLA.writeOutput(inFile,"Value at the index " + to_string(index) + " is " + to_string(flag) + ".");
            }
        }
        else if(choice == 4)
        {
            // Asks user for index
            cout << "Enter the index you want to set: " << endl;
            cin >> index;

            mLA.writeOutput(inFile, "Enter the index you want to see: ");
            mLA.writeOutput(inFile, to_string(index));

            // Asks user for value
            cout << "Enter the value you want to set: " << endl;
            cin >> value;

            mLA.writeOutput(inFile, "Enter the value you want to set: ");
            mLA.writeOutput(inFile, to_string(value));

            flag = mLA.set(index, value);
            
            // If the flag is -1, then index does not exist
            if(flag == -1)
            {
                cout << "Index does not exist." << endl;
                mLA.writeOutput(inFile, "Index does not exist.");
            }

            // Otherwise replaces value and returns the old value at the inputted index
            else
            {
                cout << "The old value at the index " << index << " is " << flag << endl;
                mLA.writeOutput(inFile,"The old value at the index " + to_string(index) + " is " + to_string(flag) + ".");
            }
        }
        else if(choice == 5)
        {
            // Asks user for index
            cout << "Enter the index you want to insert: " << endl;
            cin >> index;

            mLA.writeOutput(inFile, "Enter the index you want to insert: ");
            mLA.writeOutput(inFile, to_string(index));

            //Asks user for value
            cout << "Enter the value you want to insert: " << endl;
            cin >> value;

            mLA.writeOutput(inFile, "Enter the value you want to insert: ");
            mLA.writeOutput(inFile, to_string(value));
            
            flag = mLA.insert(index, value);

            // If flag is -2, then the list is at max size
            if(flag == -2)
            {
                cout << "List is at MAX size!" << endl;
                mLA.writeOutput(inFile, "List is at MAX size!");
            }

            //If the flag is -1, then the index does not exist
            else if(flag == -1)
            {
                cout << "Index does not exist." << endl;
                mLA.writeOutput(inFile, "Index does not exist.");
            }

            // Otherwise returns the new size of list when inserting a value at the inputted index
            else
            {
                cout << "The new size of the list is: " << flag << endl;
                mLA.writeOutput(inFile, "The size of the list is: " + to_string(flag));
            }
        }
        else if(choice == 6)
        {
            // Asks user for index
            cout << "Enter the index you want to erase: " << endl;
            cin >> index;

            mLA.writeOutput(inFile, "Enter the index you want to erase: ");
            mLA.writeOutput(inFile, to_string(index));
            
            flag = mLA.erase(index);

            // If flag is -2 then the list is empty
            if(flag == -2)
            {
                cout << "List is at empty size!" << endl;
                mLA.writeOutput(inFile, "List is at empty size!");
            }

            // If flag is -1 then the index does not exist
            else if(flag == -1)
            {
                cout << "Index does not exist." << endl;
                mLA.writeOutput(inFile, "Index does not exist.");
            }

            // Otherwise erases value and returns the erased value
            else
            {
                cout << "The old value was: " << flag << endl;
                mLA.writeOutput(inFile, "The old value was: " + to_string(flag));
            }
        }
        else if(choice == 7)
        {

            // Prints out array contents
            mLA.printList(inFile);
            mLA.writeOutput(inFile, "Index does not exist.");
        }
    }

    cout << R"(   ____                     .______.                  ._. 
  / ___\  ____    ____    __| _/\_ |__  ___.__.  ____ | | 
 / /_/  >/  _ \  /  _ \  / __ |  | __ \<   |  |_/ __ \| | 
 \___  /(  <_> )(  <_> )/ /_/ |  | \_\ \\___  |\  ___/ \| 
/_____/  \____/  \____/ \____ |  |___  // ____| \___  >__ 
        \______________/     \/      \/ \/          \/ \/ 
                                                          )" << endl;


    mLA.writeOutput(inFile, R"(   ____                     .______.                  ._. 
  / ___\  ____    ____    __| _/\_ |__  ___.__.  ____ | | 
 / /_/  >/  _ \  /  _ \  / __ |  | __ \<   |  |_/ __ \| | 
 \___  /(  <_> )(  <_> )/ /_/ |  | \_\ \\___  |\  ___/ \| 
/_____/  \____/  \____/ \____ |  |___  // ____| \___  >__ 
        \______________/     \/      \/ \/          \/ \/ 
                                                          )");
    system("pause");
}