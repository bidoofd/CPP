#ifndef MYUTILITYCLASS_H
#define MYUTILITYCLASS_H
#include <string>
#include <map>
using namespace std;

class myUtilityClass
{
    private:
        //variable names
        string name;
        map<string, int> arrMap;
    public:
        //public methods
        myUtilityClass(string name);
        int readFileInt(string fileName, string arrName);
        void displayArray();
        int writeFile();
        int countLine(string fileName);
        bool findFile(string fileName);
};

#endif
