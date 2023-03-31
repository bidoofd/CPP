#ifndef RECURSION_H
#define RECURSION_H
#include <string>

using namespace std;

class recursion
{
    private:

        string name;
        int maxSize;
        int instructions;
        int *array = new int[maxSize];
    public:
        recursion(string name);
        void reverseIterative(string fileName);
        string reverseRrecursive(ifstream& file);
        void reverseSimulatedRecursion();

        void printFile(string fileName);
        int countLine(string fileName);
        void writeOutput(ofstream& file, string line);
};

#endif