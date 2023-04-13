#include <iostream>
#include <fstream>
#include <string>
#include "bTree.h"

using namespace std;

int main()
{
    Tree binary;
    binary.insertNode("+", binary.root);
    binary.insertNode("*", binary.root);
    binary.insertNode("5", binary.root);
    binary.insertNode("1", binary.root);
    binary.insertNode("-", binary.root);
    binary.insertNode("100", binary.root);
    binary.insertNode("20", binary.root);
    cout << binary.solveExpression(binary.root) << endl;



    binary.createArray();
    //cout << "Preorder: " << endl;
    //binary.preOrder(binary.root, 0);
    //binary.printArray();
    //cout << "Postorder: " << endl;
    //binary.postOrder(binary.root, 0);
    //binary.printArray();
    cout << "inorder: " << endl;
    binary.inOrder(binary.root, 0);
    //binary.printArray();

    system("pause");
}