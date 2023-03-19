#ifndef MYQUEUEADT_H
#define MYQUEUEADT_H
#include <string>

using namespace std;

class myQueueADT
{
    private:
        string name;
        int rear, front;
        int size;
        int *array = new int[size];
    public:
        myQueueADT(string name, int size);
        int qSize();
        int emptyFlag();
        int fullFlag();
        int firstInQ();
        int enqueue(int num);
        int dequeue();

        void writeOutput(ofstream& file, string line);
};

#endif