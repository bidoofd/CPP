#ifndef MYUTILITYCLASS_H
#define MYUTILITYCLASS_H
#include <string>
#include <unordered_map>
#include <list>
#include <vector>
#include <ctime>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

class myUtilityClass
{
    private:
        //variable names
        //  - string name : name of object
        //  - unordered_map arrMap : hashmap of stored arrays
        //  - time_point startTime : start time of timer
        //  - time_point endTime : end time of timer
        string name;
        unordered_map<string, vector<int>> arrMap;
        steady_clock::time_point startTime;
        steady_clock::time_point endTime;
    public:
        //public methods
        //  - myUtilityClass : creates class object based on name
        //  - readFileInt : reads integer types of files
        //  - writeFileInt : writes out to a file specifically for integers
        //  - displayArray : displays the arrays stored in hashmap
        //  - countLine : counts the lines in the file to set size for array
        //  - findFile : whether or not filepath entered is valid
        //  - writeOutput : constantly writes out to a recording file
        //  - startTimer : starts the timer
        //  - endTimer : ends the timer
        //  - printTime : prints out timer
        myUtilityClass(string name);
        int readFileInt(string fileName, string arrName);
        int writeFileInt(string arrName, int arrSize, string outFileName, int repeat);
        void displayArray();
        int countLine(string fileName);
        bool findFile(string fileName);
        void writeOutput(fstream& file, string line); // soon to be outputs every input into a file
        void startTimer();
        void endTimer();
        void printTime();
};

#endif
