#ifndef MYUTILITYCLASS_H
#define MYUTILITYCLASS_H
#include <string>
#include <map>
using namespace std;

class myUtilityClass
{
    private:
        string name;
        map<string, int> arrMap;
    public:
        myUtilityClass();
        myUtilityClass(string name);
        int readFileInt(string fileName, string arrName);
        void displayArray();
        int writeFile();
        int countLine(string fileName);
};

#endif
