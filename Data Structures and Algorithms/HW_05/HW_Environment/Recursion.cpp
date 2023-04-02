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
    this->array = new int[this->maxSize + 1];
    int count = 0;

    if(inFile.is_open())
    {
        while(getline(inFile, line))
        {
            int value = stoi(line);
            this->array[count] = value;
            count++;
        }
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
    cout << this->array[this->maxSize - 1] << "]\n" << endl;

    cout << "The reverse order of the array is: " << endl;
    cout << "[";
    for(int a = this->maxSize - 1; a > 0; a--)
    {
        cout << this->array[a] << ", ";
    }
    cout << this->array[0] << "]\n" << endl;

    delete this->array;

}

string recursion::reverseRrecursive(ifstream& fname)
{
    if(fname.eof())
    {
        return "";
    }
    string line;
    getline(fname, line);
    return line + "\n" + reverseRrecursive(fname);
}

void recursion::reverseSimulatedRecursion(string fname)
{
    string line;
    ifstream inFile(fname);
    int count = 0;

    if(inFile.is_open())
    {
        while(getline(inFile, line))
        {
            int value = stoi(line);
            this->array[count] = value;
            count++;
        }
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
    cout << this->array[this->maxSize - 1] << "]\n" << endl;

    cout << "The reverse order of the array is: " << endl;
    cout << "[";
    for(int a = this->maxSize - 1; a > 0; a--)
    {
        cout << this->array[a] << ", ";
    }
    cout << this->array[0] << "]\n" << endl;

    delete this->array;
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

int recursion::getInstructions()
{
    return this->instructions;
}

void recursion::resetInstructions()
{
    this->instructions = 0;
}

void recursion::writeOutput(ofstream& recFile, string line)
{
    //writes to the output file and ends with a newline
    recFile << line << endl;

    // 1 for writing to file operation

    this->instructions = 1;
}