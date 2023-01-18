#ifndef MYUTILITYCLASS_H
#define MYUTILITYCLASS_H
#include <string>
#include <unordered_map>
#include <list>
#include <vector>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

class myUtilityClass
{
    private:
        //variable names
        string name;
        unordered_map<string, vector<int>> arrMap;
        steady_clock::time_point startTime;
        steady_clock::time_point endTime;
    public:
        //public methods
        myUtilityClass(string name);
        int readFileInt(string fileName, string arrName);
        int writeFileInt(string arrName, int arrSize, string outFileName);
        void displayArray();
        int writeFile();
        int countLine(string fileName);
        bool findFile(string fileName);
        void writeOutput();
        void startTimer();
        void endTimer();
        void printTime();
};

#endif
