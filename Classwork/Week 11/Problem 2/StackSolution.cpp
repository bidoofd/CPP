#include "StackSolution.h"

Stack::Stack() { 
    top = -1; 
	for (int i=0; i< MAX; i++) 
	     myStack[i] =0;	
}  
bool Stack::push(int item){
	if (top >= (MAX-1)) {
		cout << "Stack Overflow!!! can not push " << item << endl;
		return false;
    }
	else {
		myStack[++top] = item;
		cout<<item<<endl;
		return true;
   }
}
  
//removes or pops elements out of the stack
int Stack::pop()
{
   if (top < 0) {
		cout << "Stack Underflow!!\n";
		return 0;
   }
   else {
		int item = myStack[top];
		myStack[top--] = 0;
	return item;
   }
}
  
//check if stack is empty
bool Stack::isEmpty()
{
   return (top < 0);
}

// check if stack is full
bool Stack::isFull() 
{
	return (top == MAX-1);
}  

int Stack::size()
{
	int count = 0;
	for(int a = 0; a < MAX; a++)
	{
		if(myStack[a] != 0)
		{
			count = count + 1;
		}
		else if(myStack[a] == 0)
		{
			break;
		}
	}
	return count;
}

int Stack::topStack()
{
	return myStack[top];
}

int Stack::bottom()
{
	return myStack[0];
}

void Stack::display()
{
	cout << "Stack is from bottom to top: " << endl;
	cout << "BOTTOM\n--------" << endl;
	for(int a = 0; a < MAX; a++)
	{
		if(myStack[a] != 0)
		{
			cout << myStack[a] << endl;
		}
	}
	cout << "--------\nTOP" << endl;
}