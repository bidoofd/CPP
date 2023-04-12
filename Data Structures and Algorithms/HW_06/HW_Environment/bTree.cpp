#include "bTree.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

Tree::Tree()
{
    root = NULL;
}

Node* Tree::createNode(int value)
{
    Node* newNode = new Node(value);
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL; 
    return newNode;
}

Node* Tree::insertNode(int array[], int rank, int size)
{
    Node *root = NULL;
    if(rank < size)
    {
        root = createNode(array[rank]);
        root->left = insertNode(array, 2 * rank + 1, size);
        root->right = insertNode(array, 2 * rank + 2, size);
    }
    return root;
}

void Tree::inOrder(Node* root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}