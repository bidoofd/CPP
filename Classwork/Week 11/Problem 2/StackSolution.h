#include<iostream>
using namespace std;
  
#define MAX 100 //max size for stack
  
class Stack
{
   public :
   int top;
   int myStack[MAX]; //stack array
  
   Stack();
   bool push(int x); // insert item into stack
   int pop();	     // remove the most recent item 
   bool isEmpty();  // return true if stack is empty
   bool isFull();  // return true if stack is full, you need to implement this operation
   int size(); //operation that returns the number of elements in the stack; 
   int topStack(); //operation that returns the element at the top of the stack
   int bottom(); //operation that returns the element at the bottom of the stack
   void display(); //operation that displays all the stack elements without changing the stack
};