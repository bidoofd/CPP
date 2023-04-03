#include "Recursion.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Bool is number functions to check if a number is a string.
bool is_num(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

//Binary search algorithm
int bSearch(int array[], int left, int right, int value)
{
    if(left > right)
    {
        return -1;
    }
    else
    {
        int middle = (left + right) / 2;

        if(array[middle] == value)
        {
            return middle;
        }
        else if(array[middle] > value)
        {
            return bSearch(array, left, middle - 1, value);
        }
        else
        {
            return bSearch(array, middle + 1, right, value);
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//sets up recursion class
recursion::recursion(string n)
{
    //Sets up class with name
    this->name = n;
}

void recursion::reverseIterative(string fname)
{
    // Variables
    //  - line: used for getting string input and file input
    //  - inFile: File object
    //  - count: counts to store values
    string line;
    ifstream inFile(fname);
    this->maxSize = countLine(fname);
    this->array = new int[this->maxSize + 1];
    int count = 0;

    // while the file is able top be opened
    if(inFile.is_open())
    {
        // get the line
        while(getline(inFile, line))
        {
            //convert it over to an int value and store into array.
            //increase count
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

    //prints out the array normally
    cout << "The original order of the array is: " << endl;
    cout << "[";
    for(int a = 0; a < this->maxSize - 1; a++)
    {
        cout << this->array[a] << ", ";
    }
    cout << this->array[this->maxSize - 1] << "]\n" << endl;

    //prints out the array in reverse order
    cout << "The reverse order of the array is: " << endl;
    cout << "[";
    for(int a = this->maxSize - 1; a > 0; a--)
    {
        cout << this->array[a] << ", ";
    }
    cout << this->array[0] << "]\n" << endl;

    delete this->array;

}

void recursion::reverseRrecursive(ifstream& file)
{
    string line;
    if(file >> line)
    {
        cout << line << " ";
        reverseRrecursive(file);
        cout << line << " ";
    }
    else if (file.eof())
    {
        cout << endl;
        cout << "The reverse order of the list is: " << endl;
    }
    file.close();
}

void recursion::reverseSimulatedRecursion(string fname)
{
    string line;
    ifstream inFile(fname);

    stack<int> stack;

    if(inFile.is_open())
    {
        cout << "The original order of the stack is: " << endl;
        cout << "[";
        while(getline(inFile, line))
        {
            int value = stoi(line);
            cout << value << ", ";
            stack.push(value);
        }
        cout << "]" << endl;
        inFile.close();
    }
    else
    {
        cout << "File not found." << endl;
    }

    cout << "The reverse order of the array is: " << endl;
    cout << "[";
    while(!stack.empty())
    {
        cout << stack.top() << ", ";
        stack.pop();
    }
    cout << "]" << endl;
}

void recursion::binarySearch(string fname)
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

    bool boolFlag = true;
    string stringValue;
    int value;

    //asks user for input
    cout << "Enter the value to find: " << endl;
    while(boolFlag)
    {
        getline(cin, stringValue);
        // uses is_number function to see if inputted value is a num
        if(is_num(stringValue) == false)
        {
            cout << "Not a valid value" << endl;
            //if it isnt, then have the user re enter value until num
        }
        else if(is_num(stringValue) == true)
        {
            //convert string to int and end loop
            value = stoi(stringValue);
            if(value >= 0)
            {
                boolFlag = false;
            }
            else
            {
                cout << "Cannot enter a negative number." << endl;
            }
        }
    }

    int foundValue = bSearch(this->array, 0, count, value);

    if(foundValue == -1)
    {
        cout << "The value " << value << " was not found in the array." << endl;
    }
    else
    {
        cout << "The value " << value <<  " was found in the array at position: " << foundValue << "." << endl;
    }

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