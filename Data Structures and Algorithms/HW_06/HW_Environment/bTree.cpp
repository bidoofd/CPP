#include "bTree.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

Tree::Tree(string name)
{
    this->name = name;
    root = NULL;
}

void Tree::insertNode(string value, Node* currentNode)
{
    if(currentNode == NULL)
    {
        //if the current node is root create new node from value and make it root
        Node* newNode = new Node(value);
        this->root = newNode;
        cout << "The node has been made as the root." << endl;
    }
    else
    {
        int choice = 0;
        while(choice != 5)

        //traversal/insertion menu
        {
            cout << "The value you are trying to insert is " << value << endl;
            cout << "The node you are currently at is indicated by this data: " << currentNode->data << endl;
            cout << "What would you like to do? " << endl;
            cout << "1. Insert Node value Left" << endl;
            cout << "2. Insert Node value Right" << endl;
            cout << "3. Move into left node" << endl;
            cout << "4. Move into right node" << endl;
            cout << "5. STOP" << endl;

            cin >> choice;

            if(choice == 1)
            {
                //checks to see if a value already exists
                if(currentNode->left == NULL)
                {
                    //if it doesnt insert new node
                    Node* newNode = new Node(value);
                    currentNode->left = newNode;
                    cout << "Successfully created left node." << endl;
                    return;
                }
                else
                {
                    cout << "Cannot enter value here." << endl;
                }
            }
            //same process for right node
            else if(choice == 2)
            {
                if(currentNode->right == NULL)
                {
                    Node* newNode = new Node(value);
                    currentNode->right = newNode;
                    cout << "Successfully created right node." << endl;
                    return;
                }
                else
                {
                    cout << "Cannot enter value here." << endl;
                }
            }
            //checks to see if there is an actual node to move to
            else if(choice == 3)
            {
                if(currentNode->left != NULL)
                {
                    //if node exists, move to that node
                    insertNode(value, currentNode->left);
                    break;
                }
                else
                {
                    cout << "Cannot move here" << endl;
                }
            }
            else if(choice == 4)
            {
                if(currentNode->right != NULL)
                {
                    insertNode(value, currentNode->right);
                    break;
                }
                else
                {
                    cout << "Cannot move here" << endl;
                }
            }
            else if(choice == 5)
            {
                break;
            }
        }
    }

}

void Tree::insertNodeAuto(string fileName)
{
    string line;
    ifstream inFile(fileName);

    // while the file is able top be opened
    if(inFile.is_open())
    {
        // get the line
        while(getline(inFile, line))
        {
            //create new node
            Node* newNode = new Node(line);
            //if the root is null set the root to new node value
            if(this->root == NULL)
            {
                this->root = newNode;
                continue;
            }
            //create a queue for nodes.
            //  the reason for this is because queues ise the FIFO property.
            //  this is useful for binary trees in breadth first traversal
            //  that is how this algorithm is creating the binary tree
            queue<Node*> nodeQueue;
            //Push root into queue
            nodeQueue.push(this->root);
            //while the queue is not empty
            while(nodeQueue.empty() == false)
            {
                //make the current node whatever node is at the front of the queue
                Node* currentNode = nodeQueue.front();
                // remove that node from queue since it is in use
                nodeQueue.pop();

                // if the left node of the current node exists
                if(currentNode->left != NULL)
                {
                    //push that node into the queue
                    nodeQueue.push(currentNode->left);
                }
                else
                {
                    //otherwise make the left node of that current node the new node
                    currentNode->left = newNode;
                    break;
                }

                if(currentNode->right != NULL)
                {
                    nodeQueue.push(currentNode->right);
                }
                else
                {
                    currentNode->right = newNode;
                    break;
                }
            }

        }
        inFile.close();
    }
    else
    {
        cout << "File not found." << endl;
    }

    this->size = totalNodes(this->root);
}

void Tree::resetTree()
{
    this->root = NULL;
}

void Tree::preOrder(Node* root, int count)
{
    if(root != NULL)
    {   
        //this->array[count++] = root->data;
        this->stack.push(root->data);
        cout << root->data << " ";
        preOrder(root->left, count);
        preOrder(root->right, count);
    }
}

void Tree::postOrder(Node* root, int count)
{
    if(root != NULL)
    {
        postOrder(root->left, count);
        postOrder(root->right, count);
        //this->array[count++] = root->data;
        this->stack.push(root->data);
        cout << root->data << " ";
    }
}


void Tree::inOrder(Node* root, int count)
{
    if(root != NULL)
    {
        inOrder(root->left, count);
        //this->array[count++] = root->data;
        this->stack.push(root->data);
        cout << root->data << " ";
        inOrder(root->right, count);
    }
}

int Tree::solveExpression(Node* root)
{
    if(root->left == NULL && root->right == NULL)
    {
        return int(root->data.c_str());
    }
    else
    {
        int left_value = solveExpression(root->left);
        int right_value = solveExpression(root->right);
        if(root->data == "*")
        {
            return left_value * right_value;
        }
        else if(root->data == "-")
        {
            return left_value - right_value;
        }
        else if(root->data == "+")
        {
            return left_value + right_value;
        }
        return left_value / right_value;
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

void Tree::printArray()
{
    for(int a = 0; a < this->size; a++)
    {
        //cout << this->array[a] << " ";
        cout << stack.front() << " ";
        stack.pop();
    }
}

int Tree::countLine(string fname)
{
    //variable names
    string line;
    int count = 0;
    ifstream inFile(fname);
    //if statement for opening file
    if(inFile.is_open())
    {
        //if true go in a while loop and count
        while(getline(inFile, line))
        {
            count++;
        }
        //closes file
        inFile.close();
    }
    else
    {
        //otherwise do nothing but print
        cout << "Unable to open file." << endl;
    }
    //returns count of lines if file can open
    return count;
}

void Tree::resetInstructions()
{
    this->instructions = 0;
}

void Tree::writeOutput(ofstream& recFile, string line)
{
    //writes to the output file and ends with a newline
    recFile << line << endl;

    // 1 for writing to file operation

    this->instructions = 1;
}