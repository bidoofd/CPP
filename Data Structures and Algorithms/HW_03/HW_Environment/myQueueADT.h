#ifndef MYQUEUEADT_H
#define MYQUEUEADT_H
#include <string>

using namespace std;

class myQueueADT
{
    private:
        // Variables (int)
        //  - rear: last position in the queue
        //  - front: first position in the queue
        //  - size: max size of the queue
        //  - *array: dynamically creates array based on size

        // Variables (string)
        //  - name: name for object

        string name;
        int rear, front;
        int size;
        int *array;

        int instructions = 0;
    public:
        // Methods (int)
        //  - myQueueADT(): creates the myQueueADT object
        //      - @ Parameters
        //          - name: name of object
        //          - size: size of the objet queue
        //  - qSize(): returns MAX size of the array
        //  - emptyFlag(): returns true if queue is empty, false if it is not
        //  - fullFlag(): returns true if queue is full, false if it is not
        //  - firstInQ(): returns the first number in the queue
        //  - enqueue(): inserts a value into the queue
        //      - @ Parameters
        //          - num: value to be inserted into the queue
        //  - dequeue(): removes the value at the beginning of the queue

        // Methods (string)
        //  - writeOutput(): writes to external file
        //      - @ Parameters
        //          - file: file name to be written
        //          - line: string to be written into the file

        myQueueADT(string name, int size);
        int qSize();
        int emptyFlag();
        int fullFlag();
        int firstInQ();
        int enqueue(int num);
        int dequeue();

        int getInstructions();
        void resetInstructions();

        void writeOutput(ofstream& file, string line);
};

#endif