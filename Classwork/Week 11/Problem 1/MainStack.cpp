#include "Stack.h"

// main program to demonstrate stack functions
int main()
{
   // a) create a stack object
   Stack S;
   
   // b) call push operation three times with value 2, 4 and 6
   S.push(2);
   S.push(6);
   S.push(4);
   
   // c) check if stack is full

   cout << S.isFull() << endl;
   
   // d) empty the stack, you need to iterate (for loop) over the stack and print the item before removing it

   for(int a = 0; a < 100; a++)
   {
      S.pop();
   }

   // e) check if the stack is empty
  
   cout << S.isEmpty() << endl;
   
   return 0;
}