#ifndef BTREE_H
#define BTREE_H
#include <string>

using namespace std;

struct Node
{
    string data;
    Node* left;
    Node* right;
    Node(string value)
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
        string *array;
        Tree();
        void insertNode(string value, Node* currentNode);

        void preOrder(Node* root, int count);
        void postOrder(Node* root, int count);
        void inOrder(Node* root, int count);
        int solveExpression(Node* root);

        int totalNodes(Node* root);

        void createArray();
        void printArray();
};

#endif