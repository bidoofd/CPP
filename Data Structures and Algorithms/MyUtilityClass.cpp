#include "myUtilityClass.h"
#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

//sets up name for object
myUtilityClass::myUtilityClass(string n)
{
    this->name = n;
}

//counts the line in the file to set size for array
int myUtilityClass::countLine(string fname)
{
    //variable names
    string line;
    int count = 0;
    ifstream inFile(fname);
    //if statement for opening file
    if(inFile.is_open())
    {
        //if true go in a while loop and count
        while(getline(inFile, line))
        {
            count++;
        }
        //closes file
        inFile.close();
    }
    else
    {
        //otherwise do nothing but print
        cout << "Unable to open file." << endl;
    }
    //returns count of lines if file can open
    return count;
}

//bool to see if a file exists
bool myUtilityClass::findFile(string fileName)
{
    //variable name to open file
    ifstream inFile(fileName);
    //if statement to open file
    if(inFile.is_open())
    {
        //if file is found close and return true
        inFile.close();
        return true;
    }
    else
    {
        //otherwise return false
        return false;
    }
}

//reads intger type files
int myUtilityClass::readFileInt(string fname, string arrName)
{
    //variable names
    string line;
    ifstream inFile(fname);
    int size = countLine(fname);
    int arr[size];
    int count = 0;

    //if statement to open file
    if(inFile.is_open())
    {
        //if true then while loop
        while(getline(inFile, line))
        {
            //while loop to getline in file and store into variable line
            //string line value is converted to int and stored into int value
            int value = stoi(line);
            //int value is then stored into array int arr[count] based on count
            arr[count] = value;
            //add to count in the array for positional movement
            count++;
        }
        //close file
        inFile.close();
    }
    else
    {
        //if file isnt found return -1
        return -1;
    }


    //After the file is done being read, it will store it into a the object's
    //hash map with the entered array name being the key, and the value of
    //the array int arr[a]
    for(int a = 0; a < size; a++)
    {
        //int arra[a] element is stored into int value
        int value = arr[a];
        //uses hashmap insert function for key and value
        this->arrMap.insert(make_pair(arrName + ": Arr[" + to_string(a) + "]", value));
    }

    return count;
}

void myUtilityClass::displayArray()
{
    //When printing it cannot guarantee order due to it being a hashmap (unless linked hashmap?)
    for(auto a = this->arrMap.cbegin(); a != arrMap.cend(); a++)
    {
        cout << a->first << ": " << a->second << endl;
    }
}