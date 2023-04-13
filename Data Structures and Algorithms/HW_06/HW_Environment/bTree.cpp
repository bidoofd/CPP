#include "bTree.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <stack>

using namespace std;

int toInt(string s)
{
    int num = 0;
         
    // Check if the integral value is
    // negative or not
    // If it is not negative, generate the number
    // normally
    if(s[0]!='-')
        for (int i=0; i<s.length(); i++)
            num = num*10 + (int(s[i])-48);
    // If it is negative, calculate the +ve number
    // first ignoring the sign and invert the
    // sign at the end
    else
    {
      for (int i=1; i<s.length(); i++)
        num = num*10 + (int(s[i])-48);
      num = num*-1;
    }
     
    return num;
}

Tree::Tree()
{
    root = NULL;
}

void Tree::insertNode(string value, Node* currentNode)
{
    if(currentNode == NULL)
    {
        Node* newNode = new Node(value);
        this->root = newNode;
    }
    else
    {
        int choice = 0;
        while(choice != 5)
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
                if(currentNode->left == NULL)
                {
                    Node* newNode = new Node(value);
                    currentNode->left = newNode;
                    break;
                }
                else
                {
                    cout << "Cannot enter value here." << endl;
                }
            }
            if(choice == 2)
            {
                if(currentNode->right == NULL)
                {
                    Node* newNode = new Node(value);
                    currentNode->right = newNode;
                    break;
                }
                else
                {
                    cout << "Cannot enter value here." << endl;
                }
            }
            if(choice == 3)
            {
                if(currentNode->left != NULL)
                {
                    insertNode(value, currentNode->left);
                    break;
                }
                else
                {
                    cout << "Cannot move here" << endl;
                }
            }
            if(choice == 4)
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
    }
    }

}

void Tree::preOrder(Node* root, int count)
{
    if(root != NULL)
    {     
        this->array[count++] = root->data;
        cout << root->data << endl;
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
        this->array[count++] = root->data;
        cout << root->data << endl;
    }
}


void Tree::inOrder(Node* root, int count)
{
    if(root != NULL)
    {
        inOrder(root->left, count);
        this->array[count++] = root->data;
        cout << root->data << endl;
        inOrder(root->right, count);
    }
}

int Tree::solveExpression(Node* root)
{
    if(root->left == NULL && root->right == NULL)
    {
        return toInt(root->data);
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

void Tree::createArray()
{
    this->size = totalNodes(this->root);
    this->array = new string[totalNodes(this->root)];
    cout << "Array created successfully" << endl;
}

void Tree::printArray()
{
    for(int a = 0; a < this->size; a++)
    {
        cout << this->array[a] << endl;
    }
    delete this->array;
}