// Course #: ENGR-3440-A
// Semester: Spring 2023
// Name: Jason Tran Do
// Assignment #: 2. List ADT

// Note that the use of cin and getline are being used differently
//  - cin is used for ints and number values
//  - getline is being used for strings with spaces

#include <iostream>
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
    string name;

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
    getline(cin, name);

    myListADT mLA(name, size);

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
        if(choice == 1)
        {
            // Sets flag to result of function
            flag = mLA.isEmpty();

            // If function results in 1, list is empty
            if(flag == 1)
            {
                cout << "The list is empty." << endl;
            }
            // Otherwise list is not empty
            else if(flag == 0)
            {
                cout << "The list is not empty." << endl;
            }
        }
        else if(choice == 2)
        {
            // Prints out the size of list BUT NOT MAX size
            cout << "The size of the list is: " << mLA.size() << endl;
        }
        else if(choice == 3)
        {
            // Asks user for index
            cout << "Enter the index you want to see: " << endl;
            cin >> index;
            flag = mLA.at(index);
            // If flag is -1 then index does not exist
            if(flag == -1)
            {
                cout << "Index does not exist." << endl;
            }
            // Otherwise displays the value at inputted index
            else
            {
                cout << "Value at the index " << index << " is " << flag << "." << endl;
            }
        }
        else if(choice == 4)
        {
            // Asks user for index
            cout << "Enter the index you want to set: " << endl;
            cin >> index;

            // Asks user for value
            cout << "Enter the value you want to set: " << endl;
            cin >> value;
            flag = mLA.set(index, value);
            
            // If the flag is -1, then index does not exist
            if(flag == -1)
            {
                cout << "Index does not exist." << endl;
            }

            // Otherwise replaces value and returns the old value at the inputted index
            else
            {
                cout << "The old value at the index " << index << " is " << flag << endl;
            }
        }
        else if(choice == 5)
        {
            // Asks user for index
            cout << "Enter the index you want to insert: " << endl;
            cin >> index;

            //Asks user for value
            cout << "Enter the value you want to insert: " << endl;
            cin >> value;
            
            flag = mLA.insert(index, value);

            // If flag is -2, then the list is at max size
            if(flag == -2)
            {
                cout << "List is at MAX size!" << endl;
            }

            //If the flag is -1, then the index does not exist
            else if(flag == -1)
            {
                cout << "Index does not exist." << endl;
            }

            // Otherwise returns the new size of list when inserting a value at the inputted index
            else
            {
                cout << "The new size of the list is: " << flag << endl;
            }
        }
        else if(choice == 6)
        {
            // Asks user for index
            cout << "Enter the index you want to erase: " << endl;
            cin >> index;
            
            flag = mLA.erase(index);

            // If flag is -2 then the list is empty
            if(flag == -2)
            {
                cout << "List is at empty size!" << endl;
            }

            // If flag is -1 then the index does not exist
            else if(flag == -1)
            {
                cout << "Index does not exist." << endl;
            }

            // Otherwise erases value and returns the erased value
            else
            {
                cout << "The old value was: " << flag << endl;
            }
        }
        else if(choice == 7)
        {

            // Prints out array contents
            mLA.printList();
        }
    }

    cout << R"(   ____                     .______.                  ._. 
  / ___\  ____    ____    __| _/\_ |__  ___.__.  ____ | | 
 / /_/  >/  _ \  /  _ \  / __ |  | __ \<   |  |_/ __ \| | 
 \___  /(  <_> )(  <_> )/ /_/ |  | \_\ \\___  |\  ___/ \| 
/_____/  \____/  \____/ \____ |  |___  // ____| \___  >__ 
        \______________/     \/      \/ \/          \/ \/ 
                                                          )" << endl;
}