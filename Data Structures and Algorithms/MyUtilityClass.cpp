#include "myUtilityClass.h"
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

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

void myUtilityClass::startTimer()
{
    this->startTime = steady_clock::now();
}

void myUtilityClass::endTimer()
{
    this->endTime = steady_clock::now();
}

void myUtilityClass::printTime()
{
    cout << "Time format in HH:MM:SS.MS" << endl;
    //cout << date::hh_mm_ss{duration_cast<milliseconds>(this->startTime - this->endTime)};
    cout << setw(2) << setfill('0') << duration_cast<hours>(this->endTime - this->startTime).count() << ":"  << setw(2) << setfill('0') << duration_cast<minutes>(this->endTime - this->startTime).count() << ":" << setw(2) << setfill('0')  << duration_cast<milliseconds>(this->endTime - this->startTime).count() / 1000.0 << endl;
}

void myUtilityClass::writeOutput(fstream& recFile, string line)
{
    recFile << line << endl;
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
        this->arrMap[arrName].push_back(value);
    }

    return count;
}

int myUtilityClass::writeFileInt(string arrName, int arrSize, string outFileName)
{
    /*A method to write the content of an array into an output file. The method should get the array
    name, the array size and the name of the output file as arguments. The method will run through
    the array and write all the elements to the output file then return the value 1 (indicating
    successful writes). Exceptions for file handling must be handled inside the method and the
    appropriate error messages must be displayed. In this case, the method should also return -1.*/

    string line;

    ofstream inFile(outFileName);
    int arr[arrSize];
    if(inFile.is_open())
    {
        cout << "Enter values to write into file: " << endl;
        for(int a = 0; a < arrSize; a++)
        {
            cin >> line;
            inFile << line << endl;  
        }
        inFile.close();
        return 1;
    }
    else
    {
        cout << "Error writing to file" << endl;
        inFile.close();
        return -1;
    }
}

void myUtilityClass::displayArray()
{
    //When printing it cannot guarantee order due to it being a hashmap (unless linked hashmap?)
    for(auto a = this->arrMap.cbegin(); a != arrMap.cend(); a++)
    {
        cout << "Key: " << a->first << endl;
        for(auto b = a->second.begin(); b != a->second.end(); b++)
        {
            cout << "Value: " << *b << endl;
        }
    }
}