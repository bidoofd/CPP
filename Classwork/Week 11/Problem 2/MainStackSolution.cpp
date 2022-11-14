#include "StackSolution.h"

// main program to demonstrate stack functions
int main()
{
  
   // Step 1:) create a stack object
   Stack stack;
   
   // Step 2:) call push operation three times with value 2, 4 and 6
   cout<<"The Stack Push "<<endl;
   stack.push(2);
   stack.push(4);
   stack.push(6);

      cout << "\n\n\n" << endl;

   cout << "Size of stack: " << stack.size() << endl;
   cout << "Top of stack: " << stack.topStack() << endl;
   cout << "Bottom of stack: " << stack.bottom() << endl;
   stack.display();
   
   cout << "\n\n\n" << endl;
   
   // Step 3:) check if stack is full
   if (stack.isFull() )
	   cout << "Stack is full" << endl;
   else
	   cout << "Stack is not full" <<endl;
   
   
   // Step 4:) iterate (for loop) over the stack and remove all the item   
   cout<<"The Stack Pop : "<<endl;
   while(!stack.isEmpty())
         cout<<stack.pop()<<endl;

cout << "\n\n\n" << endl;

   // Step 5:) check if the stack is empty
   if (stack.isEmpty() )
	   cout << "Stack is empty" << endl;
   else
	   cout << "Stack is not empty" <<endl;


cout << "\n\n\n" << endl;
   //Testing new operations

   cout << "Size of stack: " << stack.size() << endl;
   cout << "Top of stack: " << stack.topStack() << endl;
   cout << "Bottom of stack: " << stack.bottom() << endl;
   stack.display();
   return 0;
}