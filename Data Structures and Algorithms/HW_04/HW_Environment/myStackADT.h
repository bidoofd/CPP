#ifndef MYSTACKADT_H
#define MYSTACKADT_H
#include <string>

using namespace std;

class myStackADT
{
    private:

        string name;
        int topPointer;
        int maxSize;
        int instructions;
        int *stack = new int[maxSize];
    public:

        myStackADT(string name, int size);
        int size();
        bool isEmpty();
        int top();
        int push(int value);
        int pop();

        int getInstructions();
        void resetInstructions();

        void writeOutput(ofstream& file, string line);
};

#endif