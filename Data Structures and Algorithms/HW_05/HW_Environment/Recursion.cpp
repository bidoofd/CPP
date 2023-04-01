#include "Recursion.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool is_number (string line)
{
    if (isdigit(atoi(line.c_str())))
        return true;

    return false;
}

//sets up myStackADT class
recursion::recursion(string n)
{
    this->name = n;
}

void recursion::reverseIterative(string fname)
{
    string line;
    ifstream inFile(fname);
    this->maxSize = countLine(fname);
    this->array = new int[this->maxSize];
    int count = 0;

    if(inFile.is_open())
    {
        while(getline(inFile, line))
        {
            if(is_number(line))
            {
                int value = stoi(line);
                this->array[count] = value;
                count++;
            }
        }
        //resets max size to fill in for void variables that are non numbers
        this->maxSize = count;
        inFile.close();
    }
    else
    {
        cout << "File not found." << endl;
    }

    cout << "The original order of the array is: " << endl;
    cout << "[";
    for(int a = 0; a < this->maxSize - 1; a++)
    {
        cout << this->array[a] << ", ";
    }
    cout << this->array[maxSize] << "]\n" << endl;

    cout << "The reverse order of the array is : " << endl;
    cout << "[";
    for(int a = this->maxSize; a > 0; a++)
    {
        cout << this->array[a] << ",";
    }
    cout << this->array[0] << "]\n" << endl;

}

string recursion::reverseRrecursive(ifstream& file)
{
    if(file.eof())
    {
        return "";
    }
    string line;
    getline(file, line);
    return line + "\n" + reverseRrecursive(file);
}

//counts the line in the file to set size for array
int recursion::countLine(string fname)
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