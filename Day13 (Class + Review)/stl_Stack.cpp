/*
Stacks are a type of container adaptors, specifically designed to operate in a LIFO context (last-in first-out)
, where elements are inserted and extracted only from the end of the container.

stacks are implemented as containers adaptors, which are classes that use an encapsulated object of a specific
 container class as its underlying container, providing a specific set of member functions to access its elements.
 Elements are pushed/popped from the "back" of the specific container, which is known as the top of the stack.

The underlying container may be any of the standard container class templates or some other specifically
 designed container class (template < class T, class Container = deque<T> > class stack;)
 The only requirement is that it supports the following operations:


back() 
push_back() 
pop_back() 


Therefore, the standard container class templates vector, deque and list can be used. By default, if no container
 class is specified for a particular stack class, the standard container class template deque is used.
*/

#include <iostream>
#include <stack>
using namespace std;


void main()
{
	int arr[] = {4, 7, 2, 9, 5, 3, 8};
	stack<int> iStack;
	int i, sz;

	sz = sizeof(arr) / sizeof(arr[0]);
	for ( i=0 ; i<sz ; i++)
	{
		cout << "Pushing " << arr[i] << endl;
		iStack.push(arr[i]);
	}

	cout << endl << "Size of stack = " << iStack.size() << endl << endl;

	while ( !iStack.empty() )
	{
		cout << "Popping " << iStack.top() << endl;
		iStack.pop();
	}
}