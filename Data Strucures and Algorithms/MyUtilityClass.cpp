#include "myUtilityClass.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

myUtilityClass::myUtilityClass()
{

}

myUtilityClass::myUtilityClass(string n)
{
    this->name = n;
}

int myUtilityClass::countLine(string fname)
{
    string line;
    int count = 0;
    ifstream inFile(fname);
    if(inFile.is_open())
    {
        while(getline(inFile, line))
        {
            count++;
        }
        inFile.close();
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
    return count;
}

int myUtilityClass::readFile(string fname)
{
    string line;
    ifstream inFile(fname);
    int size = countLine(fname);
    int arr[size];
    int count = 0;
    if(inFile.is_open())
    {
        while(getline(inFile, line))
        {
            int value = stoi(line);
            arr[count] = value;
            count++;
        }
        inFile.close();
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
    this->arrSize = size;
    for(int a = 0; a < size; a++)
    {
        this->intArr[a] = arr[a];
    }

    return count;
}

void myUtilityClass::displayArray()
{
    for(int a = 0; a < sizeof(this->intArr)/sizeof(this->intArr[0]); a++)
    {
        cout << "Arr[" << a << "]: " << this->intArr[a] << endl;
    }
}