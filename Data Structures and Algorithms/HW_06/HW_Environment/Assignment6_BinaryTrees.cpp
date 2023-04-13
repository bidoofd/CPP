#include <iostream>
#include <fstream>
#include <string>
#include "bTree.h"

using namespace std;

int main()
{
    Tree binary;
    binary.insertNode(0);
    binary.insertNode(1);
    binary.insertNode(2);
    binary.insertNode(3);
    binary.insertNode(4);
    binary.insertNode(5);

    binary.createArray();
    binary.preOrder(binary.root, 0);
    binary.printArray();

    system("pause");
}