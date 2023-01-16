#ifndef MYUTILITYCLASS_H
#define MYUTILITYCLASS_H
#include <string>
using namespace std;

class myUtilityClass
{
    private:
        string name;
        int arrSize;
        int intArr[100];
    public:
        myUtilityClass();
        myUtilityClass(string name);
        int readFile(string fileName);
        void displayArray();
        int writeFile();
        int countLine(string fileName);
};

#endif
