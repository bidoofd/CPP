// Course #: ENGR-3440-A
// Semester: Spring 2023
// Name: Jason Tran Do
// Assignment #: 1. Preparations

// Note that the use of cin and getline are being used differently
//  - cin is used for ints and number values
//  - getline is being used for strings with spaces

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "myUtilityClass.h"

using namespace std;

int main()
{
    //Variable names
    string objectName, arrName, line;
    int choice = 1;
    int size, repeat;

    string recFile, fileName, outFileName = "/HW_01/HW_Environment/";

    //Ascii art welcome message

    cout << R"(                     .__.                                 ._. 
    __  _  __  ____  |  |    ____   ____    _____    ____ | | 
    \ \/ \/ /_/ __ \ |  |  _/ ___\ /  _ \  /     \ _/ __ \| | 
     \     / \  ___/ |  |__\  \___(  <_> )|  Y Y  \\  ___/ \| 
      \/\_/   \___  >|____/ \___  >\____/ |__|_|  / \___  >__ 
                  \/            \/      \_/     \/      \/ \/)" << endl;

    //Enter filepath for the output file to record
    //Users/trando/Desktop/coding/c++/Data Structures and Algorithms/HW_01/HW_Environment/recFile.txt

    cout << "Enter the filename for output file: " << endl;
    getline(cin, line);
    recFile.append(line);
    fstream inFile(recFile);

    //clears contents of recording output file
    inFile.open(recFile, ofstream::out | ofstream::trunc);
    inFile.close();

    //Enter the name of an object just to use methods
    cout << "Enter the name of myUtilityClass object." << endl;
    getline(cin, objectName);
    myUtilityClass mUC(objectName);

    //Writes to the output file the print statement and input
    mUC.writeOutput(inFile, "Enter the name of myUtilityClass object.");
    mUC.writeOutput(inFile, objectName);
    
    while(choice != 4)
    {
        //Menu
        cout << "Enter which option you would like to choose: " << endl;
        cout << "1. Read File" << endl;
        cout << "2. Print Arrays" << endl;
        cout << "3. Write File" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;

        mUC.writeOutput(inFile, "Enter which option you would like to choose: ");
        mUC.writeOutput(inFile, "1. Read File");
        mUC.writeOutput(inFile, "2. Print Arrays");
        mUC.writeOutput(inFile, "3. Write File");
        mUC.writeOutput(inFile, "4. Exit");
        mUC.writeOutput(inFile, to_string(choice));

        //If statement menu path
        if(choice == 1)
        {
            //Enter filepath name
            cout << "Enter the full filepath of your text file: " << endl;
            cin.ignore();
            getline(cin, line);
            fileName.append(line);

            mUC.writeOutput(inFile, "Enter the full filepath of your text file: ");
            mUC.writeOutput(inFile, fileName);

            //Enter name of array (acts as key)
            cout << "Enter the name of your array" << endl;
            cin.ignore(cin.rdbuf()->in_avail()); //clears buffer from escape character of \n from getline previously

            //Filepath test comment below
            //Users/trando/Desktop/coding/c++/Data Structures and Algorithms/abcdef.txt

            getline(cin, arrName);

            mUC.writeOutput(inFile, "Enter the name of your array");
            mUC.writeOutput(inFile, arrName);

            //If statement to see if it can find a file
            if(mUC.findFile(fileName))
            {
                //if successful prints out number of lines in file
                cout << "Success! Amount of numbers in file is: " << mUC.readFileInt(fileName, arrName) << "." << endl;
                mUC.writeOutput(inFile, "Success! Amount of numbers in file is: " + to_string(mUC.readFileInt(fileName, arrName)) + ".");
            }
            else
            {
                //otherwise does not do anything
                cout << "Unable to read file." << endl;
                mUC.writeOutput(inFile, "Unable to read file.");
            }
        }
        else if(choice == 2)
        {
            //displays array stored in hashmap
            mUC.displayArray(inFile);
            //prints stopwatch time
            mUC.printTime();
        }
        else if(choice == 3)
        {
            //Starts the timer
            mUC.startTimer();

            //Entering values
            cout << "Enter the array name. " << endl;
            cin.ignore();
            getline(cin, arrName);
            cout << "Enter the array size. " << endl;
            cin >> size;

            //File name for output file
            //Users/trando/Desktop/coding/c++/Data Structures and Algorithms/HW_01/output.txt
            cout << "Enter the full output file name. " << endl;
            cin.ignore();
            getline(cin, outFileName);
            cout << "Enter the amount of times you want the value to repeat: " << endl;
            cin >> repeat;

            //Function to write to file
            mUC.writeFileInt(arrName, size, outFileName, repeat, inFile);

            //end timer
            mUC.endTimer();
        }
    }

    //ascii art goodbye message

    cout << R"(   ____                     .______.                  ._. 
  / ___\  ____    ____    __| _/\_ |__  ___.__.  ____ | | 
 / /_/  >/  _ \  /  _ \  / __ |  | __ \<   |  |_/ __ \| | 
 \___  /(  <_> )(  <_> )/ /_/ |  | \_\ \\___  |\  ___/ \| 
/_____/  \____/  \____/ \____ |  |___  // ____| \___  >__ 
        \______________/     \/      \/ \/          \/ \/ 
                                                          )";

}