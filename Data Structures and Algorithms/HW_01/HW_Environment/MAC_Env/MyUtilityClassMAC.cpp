#include "myUtilityClassMAC.h"
#include <iostream>
#include <unistd.h>
#include <string>
#include <map>
#include <ctime>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

//sets up name for object
myUtilityClass::myUtilityClass(string n)
{
    this->name = n;
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
int myUtilityClass::readFile(string fname)
{
    //variable names
    string fileName = getenv("HOME");
    cout << fileName << endl;
    string line;
    ifstream inFile(fileName + "/Desktop/coding/c++/Data Structures and Algorithms/HW_01/HW_Environment/MAC_Env/" + fname, ios::app);
    int size = countLine(fname);
    this->array = new int[size];
    //int *arr = new int[size];
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
            this->array[count] = value;
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
    /*for(int a = 0; a < size; a++)
    {
        //int arra[a] element is stored into int value
        int value = arr[a];
        //uses hashmap insert function for key and value
        this->arrMap[arrName].push_back(value);
    }*/
    //delete []arr;
    return count;
}

int myUtilityClass::writeFileInt(string arrName, int arrSize, string outFileName, int repeat, ofstream& recFile)
{
    /*A method to write the content of an array into an output file. The method should get the array
    name, the array size and the name of the output file as arguments. The method will run through
    the array and write all the elements to the output file then return the value 1 (indicating
    successful writes). Exceptions for file handling must be handled inside the method and the
    appropriate error messages must be displayed. In this case, the method should also return -1.*/

    string line;

    ofstream inFile(outFileName);
    int *arr = new int[arrSize];
    if(inFile.is_open())
    {
        cout << "Enter values to write into file: " << endl;

        writeOutput(recFile, "Enter the values to write into file: ");
        for(int a = 0; a < arrSize; a++)
        {
            cin >> line;

            writeOutput(recFile, line);
            if(repeat == 1)
            {
                inFile << line << endl;
            }
            else if(repeat > 1)
            {
                for(int b = 0; b < repeat; b++)
                {
                    if(b == repeat - 1)
                    {
                        inFile << line;
                    }
                    else
                    {
                        inFile << line << ",";
                    }
                }
                inFile << endl;
            }  
        }
        delete []arr;
        inFile.close();
        return 1;
    }
    else
    {
        cout << "Error writing to file" << endl;
        writeOutput(recFile, "Error writing to file");
        delete []arr;
        inFile.close();
        return -1;
    }
}

void myUtilityClass::printTime()
{
    //print for clarification on format
    cout << "Time format in HH:MM:SS.MS" << endl;
    
    //prints out time using casts
    //  - setw and setfill used for the extra 0 if the time is a single digit
    cout << setw(2) << setfill('0') << duration_cast<hours>(this->endTime - this->startTime).count() << ":"  << setw(2) << setfill('0') << duration_cast<minutes>(this->endTime - this->startTime).count() << ":" << setw(2) << setfill('0')  << duration_cast<milliseconds>(this->endTime - this->startTime).count() / 1000.0 << endl;
}

void myUtilityClass::printTime(ofstream& inFile)
{
    //print for clarification on format
    cout << "Time format in HH:MM:SS.MS" << endl;
    
    //prints out time using casts
    //  - setw and setfill used for the extra 0 if the time is a single digit
    cout << setw(2) << setfill('0') << duration_cast<hours>(this->endTime - this->startTime).count() << ":"  << setw(2) << setfill('0') << duration_cast<minutes>(this->endTime - this->startTime).count() << ":" << setw(2) << setfill('0')  << duration_cast<milliseconds>(this->endTime - this->startTime).count() / 1000.0 << endl;
    stringstream line;
    line << setw(2) << setfill('0') << duration_cast<hours>(this->endTime - this->startTime).count() << ":"  << setw(2) << setfill('0') << duration_cast<minutes>(this->endTime - this->startTime).count() << ":" << setw(2) << setfill('0')  << duration_cast<milliseconds>(this->endTime - this->startTime).count() / 1000.0 << endl;

    writeOutput(inFile, "Time format in HH:MM:SS.MS");
    writeOutput(inFile, line.str());
}

void myUtilityClass::writeOutput(ofstream& recFile, string line)
{
    //writes to the output file and ends with a newline
    recFile << line << endl;
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

void myUtilityClass::displayArray(ofstream &inFile)
{
    //When printing it cannot guarantee order due to it being a hashmap (unless linked hashmap?)
    for(int a = 0; a < this->size; a++)
    {
        cout << "Value: " << this->array[a] << endl;
    }
}

//counts the line in the file to set size for array
int myUtilityClass::countLine(string fname)
{
    //variable names
    string line;
    string fileName = getenv("HOME");
    int count = 0;
    ifstream inFile(fileName + "/Desktop/coding/c++/Data Structures and Algorithms/HW_01/HW_Environment/MAC_Env/" + fname, ios::app);
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

void myUtilityClass::startTimer()
{
    //sets startTime to current point
    this->startTime = steady_clock::now();
}

void myUtilityClass::endTimer()
{
    //sets endTime to current point
    this->endTime = steady_clock::now();
}