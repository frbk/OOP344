#include <iostream>
#include "Stack.h"

using namespace std;

void main()
{
	int n;
	Stack stack;
	char yn;

	do {
		cout << "Enter a number to insert in the Stack: ";
		cin >> n;

		stack.Push(n);
		cout << "Continue (Y/N)?:";
		cin >> yn;
	} while (yn=='Y' || yn=='y');


	cout << "The Stack has " << stack.getSize() << " objects" << endl;
	while (stack.getSize())
	{
		cout << stack.Pop() << ", ";
	}
	cout << endl;

}