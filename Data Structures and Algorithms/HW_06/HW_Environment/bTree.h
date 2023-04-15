#ifndef BTREE_H
#define BTREE_H
#include <string>
#include <queue>

using namespace std;

struct Node
{
    string data;
    Node* left;
    Node* right;
    Node(string value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class Tree
{
    private:
        string name;
        int instructions;
    public:
        Node* root;
        int size;
        string *array;
        queue<string> stack;
        Tree(string name);
        void insertNode(string value, Node* currentNode);
        void insertNodeAuto(string fileName);
        void resetTree();

        void preOrder(Node* root, int count);
        void postOrder(Node* root, int count);
        void inOrder(Node* root, int count);
        int solveExpression(Node* root);

        int totalNodes(Node* root);

        void printArray();
        void writeOutput(ofstream& file, string line);
        void resetInstructions();
        int countLine(string fileName);
};

#endif