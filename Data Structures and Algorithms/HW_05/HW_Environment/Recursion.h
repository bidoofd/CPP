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
        int *array;
    public:
        recursion(string name);
        void reverseIterative(string fileName);
        string reverseRrecursive(ifstream& file);
        void reverseSimulatedRecursion(string fileName);

        int countLine(string fileName);

        int getInstructions();
        void resetInstructions();

        void writeOutput(ofstream& file, string line);
};

#endif