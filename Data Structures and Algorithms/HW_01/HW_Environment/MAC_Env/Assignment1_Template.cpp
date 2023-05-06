// Course #: ENGR-3440-A
// Semester: Spring 2023
// Name: Jason Tran Do
// Assignment #: 1. Preparations

// Note that the use of cin and getline are being used differently
//  - cin is used for ints and number values
//  - getline is being used for strings with spaces

#include <iostream>
#include <string>
#include <ctime>
#include "myUtilityClassMAC.h"

using namespace std;

int main()
{
    //Variable names
    string objectName, arrName, line;
    int choice = 1;
    int size, repeat;

    string recFile = "/Users/trando/Desktop/coding/c++/Data Structures and Algorithms/HW_01/HW_Environment/MAC_Env/";

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
    recFile.append(line + ".txt");
    ofstream inFile(recFile);

    //clears contents of recording output file
    inFile.open(recFile, ios::trunc);
    inFile.close();

    //Enter the name of an object just to use methods
    cout << "Enter the name of myUtilityClass object." << endl;
    getline(cin, objectName);
    myUtilityClass mUC(objectName);

    //Writes to the output file the print statement and input
    inFile.open(recFile);
    mUC.writeOutput(inFile, "Enter the name of myUtilityClass object.");
    mUC.writeOutput(inFile, objectName);
    
    while(choice != 5)
    {
        string fileName, outFileName = "/Users/trando/Desktop/coding/c++/Data Structures and Algorithms/HW_01/HW_Environment/MAC_Env/"; //resets filepath
        line = "";
        //Menu
        cout << "Enter which option you would like to choose: " << endl;
        cout << "1. Read File" << endl;
        cout << "2. Print Arrays" << endl;
        cout << "3. Write File" << endl;
        cout << "4. Print Time" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;

        mUC.writeOutput(inFile, "Enter which option you would like to choose: ");
        mUC.writeOutput(inFile, "1. Read File");
        mUC.writeOutput(inFile, "2. Print Arrays");
        mUC.writeOutput(inFile, "3. Write File");
        mUC.writeOutput(inFile, "4. Print File");
        mUC.writeOutput(inFile, "5. Exit");
        mUC.writeOutput(inFile, to_string(choice));

        //If statement menu path
        if(choice == 1)
        {
            //Enter filepath name
            cout << "Enter the name of your text file: " << endl;
            cin.ignore();
            getline(cin, line);
            fileName.append(line);

            //cout << fileName << endl;

            mUC.writeOutput(inFile, "Enter the name of your text file: ");
            mUC.writeOutput(inFile, fileName);

            //If statement to see if it can find a file
            int flag = mUC.readFile(fileName);
            if(flag != -1)
            {
                //if successful prints out number of lines in file
                cout << "Success! Amount of numbers in file is: " << to_string(flag) << "." << endl;
                mUC.writeOutput(inFile, "Success! Amount of numbers in file is: " + to_string(flag) + ".");
            }
            else
            {
                //otherwise does not do anything
                cout << "Unable to read file." << endl;
                mUC.writeOutput(inFile, "Unable to read file.");
            }
            cin.clear();
            fflush(stdin);
        }
        else if(choice == 2)
        {
            //displays array stored in hashmap
            mUC.displayArray(inFile);
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

            cout << "Enter the text file name. " << endl;
            cin.ignore();
            getline(cin, outFileName);
            outFileName.append(line);

            cout << outFileName << endl;
            cout << "Enter the amount of times you want the value to repeat: " << endl;
            cin >> repeat;

            //Function to write to file
            mUC.writeFileInt(arrName, size, outFileName, repeat, inFile);

            //end timer
            mUC.endTimer();
        }
        else if(choice == 4)
        {
            //prints stopwatch time
            mUC.printTime();
        }
    }

    //ascii art goodbye message

    cout << R"(   ____                     .______.                  ._. 
  / ___\  ____    ____    __| _/\_ |__  ___.__.  ____ | | 
 / /_/  >/  _ \  /  _ \  / __ |  | __ \<   |  |_/ __ \| | 
 \___  /(  <_> )(  <_> )/ /_/ |  | \_\ \\___  |\  ___/ \| 
/_____/  \____/  \____/ \____ |  |___  // ____| \___  >__ 
        \______________/     \/      \/ \/          \/ \/ 
                                                          )" << endl;

}