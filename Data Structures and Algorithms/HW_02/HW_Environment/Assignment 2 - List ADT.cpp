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
}