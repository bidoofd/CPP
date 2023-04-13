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

void Tree::insertNode(int value)
{
    Node* newNode = new Node(value);
    if(root == NULL)
    {
        root = newNode;
    }
    else
    {
        Node* currentNode = root;
        Node* parentNode;

        while(currentNode != NULL)
        {
            parentNode = currentNode;
            if(value < currentNode->data)
            {
                currentNode = currentNode->left;
                if(currentNode == NULL)
                {
                    parentNode->left = newNode;
                    return;
                }
            }
            else
            {
                currentNode = currentNode->right;
                if(currentNode == NULL)
                {
                    parentNode->right = newNode;
                    return;
                }
            }
        }
    }
}

void Tree::preOrder(Node* root, int count)
{
    if(root != NULL)
    {
        this->array[count++] = root->data;
        preOrder(root->left, count);
        preOrder(root->right, count);
    }
}

int Tree::totalNodes(Node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = totalNodes(root->left);
    int right = totalNodes(root->right);
 
    return 1 + left + right;
}

void Tree::createArray()
{
    this->size = totalNodes(this->root);
    this->array = new int[totalNodes(this->root)];
}

void Tree::printArray()
{
    for(int a = 0; a < this->size; a++)
    {
        cout << this->array[a] << endl;
    }
}