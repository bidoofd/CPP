#ifndef MYSTACKADT_H
#define MYSTACKADT_H
#include <string>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        Node(int value)
        {
            this->data = value;
            this->next = NULL;
        }
};

class myStackADT
{
    private:
        // Variables (int)
        //  - topPointer: points to top value in stack
        //  - maxSize: maxSize of array
        //  - *stack: dynamically creates array based on size
        //  - instructions: how ever many instructions are exeucted by the method

        // Variables (string)
        //  - name: name for object
        string name;
        int instructions;

        Node* topPointer;
    public:
        // Methods (int)
        //  - myStackADT(): creates the myQueueADT object
        //      - @ Parameters
        //          - name: name of object
        //          - size: size of the object stack
        //  - size(): returns MAX size of the stack
        //  - stackSize(): returns size of CURRENT stack
        //  - isEmpty(): returns true if queue is empty, false if it is not
        //  - top(): displays the first value in stack (top value)
        //  - push(): inserts value into stack
        //      - @ Parameters
        //          - value: value to be inserted into the stacl
        //  - pop(): removes the value at the top of the stack
        //  - getInstructions(): gets instructions

        // Methods (void)
        //  - resetInstructions(): sets instructions back to 0
        //  - writeOutput(): writes to external file
        //      - @ Parameters
        //          - file: file name to be written
        //          - line: string to be written into the file

        myStackADT(string name);
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