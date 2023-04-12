#ifndef BTREE_H
#define BTREE_H
#include <string>

using namespace std;

class Node
{
    public:
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
    private:
        Node* root;
    public:
        Tree();
        Node* createNode(int value);
        Node* insertNode(int array[], int rank, int size);

        void inOrder(Node* root);
};

#endif