#include <iostream>
#include <string>
#include "myListADT.h"

using namespace std;

int main()
{
    int size;
    string name;

    cout << "Enter the size of the array" << endl;
    cin >> size;

    cout << "Enter the name of myListADT object" << endl;
    getline(cin, name);

    myListADT mLA(name, size);

    cout << mLA.isEmpty() << endl;
    cout << mLA.insert(0, 1) << endl;
    cout << mLA.insert(1, 2) << endl;
    cout << mLA.insert(2, 3) << endl;
    cout << mLA.insert(3, 4) << endl;
    cout << mLA.insert(4, 5) << endl;
    cout << mLA.insert(5, 6) << endl;
}