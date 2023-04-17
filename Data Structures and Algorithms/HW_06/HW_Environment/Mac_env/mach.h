#ifndef MACH_H
#define MACH_H
#include <string>
#include <queue>

using namespace std;

struct Node
{
    // Variables
    //  data = data value of node
    //  left = left node pointer
    //  right = right node pointer
    string data;
    Node* left;
    Node* right;
    //sets up default node (root)
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
        //Variables
        //  name = name of the tree
        // instructions = amount of instructions executed
        string name;
        int instructions;
    public:
        // Root = root of tree
        // size
        Node* root;
        int size;
        string *array;
        queue<string> stack;
        Tree(string name);
        void insertNode(string value, Node* currentNode);
        void insertNodeAuto(string fileName);
        void insertNodeAuto(string value, Node* currentNode);
        void resetTree();

        void preOrder(Node* root, int count);
        void postOrder(Node* root, int count);
        void inOrder(Node* root, int count);
        int solveExpression(Node* root);
        void expressOptionTree(string word, Node* root);

        int totalNodes(Node* root);

        void printArray();
        void writeOutput(ofstream& file, string line);
        void resetInstructions();
        int countLine(string fileName);
};

#endif