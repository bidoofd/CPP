#ifndef BTREE_H
#define BTREE_H
#include <string>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class Tree
{
    public:
        Node* root;
        int size;
        int *array;
        Tree();
        void insertNode(int value);

        void preOrder(Node* root, int count);

        int totalNodes(Node* root);

        void createArray();
        void printArray();
};

#endif