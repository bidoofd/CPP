#include<iostream>
using namespace std;
  
#define MAX 100 //max size for stack
  
class Stack
{
   private:
   	int top;          //the index that points to the top of the stack 
   	int myStack[MAX]; //stack array that stores poistive int
  
   public:
   	Stack();          // initialize the top to -1 and the array elements to 0 

   	bool push(int x); // insert item x into the stack.           
                     	  // if stack is full, display "Stack Overflow" & return false, else return true
   
   	int pop();	  // remove the most recent item from the stack.  
     		          // if stack is empty, display "Stack Underflow" & return 0, else return the item
   
   	bool isEmpty();	  // return true if stack is empty
   
   	bool isFull();    // return true if stack is full
   
};