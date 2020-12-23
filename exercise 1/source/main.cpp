//#include "multipopStack.h"
//#include "boolStack.h"
#include "Stack.h"


int main()
{
	myStack<bool> stack;
	
	// "Stack is empty":
	stack.print();
	
	cout << "\nLet's add some elements\n";
	stack.push(false);
	stack.push(true);
	stack.push(false);
	stack.push(true);
	
	cout << "Current number of elements: " << stack.getCount() << endl << endl;
	stack.print();
	
	cout << "\nLet's delete 2 last elements.\n";
	stack.multipop(2);

	cout << "Current number of elements: " << stack.getCount() << endl;
	
	cout << "\nNow stack consists of: \n";
	stack.print();

	return 0;
}