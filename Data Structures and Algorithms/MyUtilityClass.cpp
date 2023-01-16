#include "myUtilityClass.h"
#include <iostream>
#include <string>
#include <fstream>
#include <map>

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

int myUtilityClass::readFileInt(string fname, string arrName)
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
        return -1;
    }



    for(int a = 0; a < size; a++)
    {
        int value = arr[a];
        this->arrMap.insert(make_pair(arrName + ": Arr[" + to_string(a) + "]", value));
    }

    return count;
}

void myUtilityClass::displayArray()
{
    for(auto a = this->arrMap.cbegin(); a != arrMap.cend(); a++)
    {
        cout << a->first << ": " << a->second << endl;
    }
}