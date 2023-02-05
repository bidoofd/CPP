#include <iostream>
#include <string>
#include "myListADT.h"

using namespace std;

int main()
{
    int size, index, value, flag;
    int choice = 1;
    string name;

    cout << "Enter the size of the array" << endl;
    cin >> size;

    cout << "Enter the name of myListADT object" << endl;
    cin.ignore();
    getline(cin, name);

    myListADT mLA(name, size);

    while(choice != 8)
    {
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
            flag = mLA.isEmpty();
            if(flag == 1)
            {
                cout << "The list is empty." << endl;
            }
            else if(flag == 0)
            {
                cout << "The list is not empty." << endl;
            }
        }
        else if(choice == 2)
        {
            cout << "The size of the list is: " << mLA.size() << endl;
        }
        else if(choice == 3)
        {
            cout << "Enter the index you want to see: " << endl;
            cin >> index;
            flag = mLA.at(index);
            if(flag == -1)
            {
                cout << "Index does not exist." << endl;
            }
            else
            {
                cout << "Value at the index " << index << " is " << flag << "." << endl;
            }
        }
        else if(choice == 4)
        {
            cout << "Enter the index you want to set: " << endl;
            cin >> index;
            cout << "Enter the value you want to set: " << endl;
            cin >> value;
            flag = mLA.set(index, value);
            if(flag == -1)
            {
                cout << "Index does not exist." << endl;
            }
            else
            {
                cout << "The old value at the index " << index << " is " << flag << endl;
            }
        }
        else if(choice == 5)
        {
            cout << "Enter the index you want to insert: " << endl;
            cin >> index;
            cout << "Enter the value you want to insert: " << endl;
            cin >> value;
            
            flag = mLA.insert(index, value);
            if(flag == -2)
            {
                cout << "List is at MAX size!" << endl;
            }
            else if(flag == -1)
            {
                cout << "Index does not exist." << endl;
            }
            else
            {
                cout << "The new size of the list is: " << flag << endl;
            }
        }
        else if(choice == 6)
        {
            cout << "Enter the index you want to erase: " << endl;
            cin >> index;
            
            flag = mLA.erase(index);
            if(flag == -2)
            {
                cout << "List is at empty size!" << endl;
            }
            else if(flag == -1)
            {
                cout << "Index does not exist." << endl;
            }
            else
            {
                cout << "The old value was: " << flag << endl;
            }
        }
        else if(choice == 7)
        {
            mLA.printList();
        }
    }
}