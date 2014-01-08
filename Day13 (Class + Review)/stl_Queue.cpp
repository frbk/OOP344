/*
queues are a type of container adaptors, specifically designed to operate in a FIFO context (first-in first-out),
 where elements are inserted into one end of the container and extracted from the other.

queues are implemented as containers adaptors, which are classes that use an encapsulated object of a specific
 container class as its underlying container, providing a specific set of member functions to access it elements.
 Elements are pushed into the "back" of the specific container and popped from its "front".

The underlying container may be one of the standard container class template or some other specifically designed
 container class (template < class T, class Container = deque<T> > class queue;).
 The only requirement is that it supports the following operations:

front() 
back() 
push_back() 
pop_front() 


Therefore, the standard container class templates deque and list can be used. By default, if no container class is
 specified for a particular queue class, the standard container class template deque is used.
*/


#include <iostream>
#include <queue>
using namespace std;


void main()
{
	int arr[] = {4, 7, 2, 9, 5, 3, 8};
	queue<int> iQueue;
	int i, sz;

	sz = sizeof(arr) / sizeof(arr[0]);
	for ( i=0 ; i<sz ; i++)
	{
		cout << "Pushing " << arr[i] << endl;
		iQueue.push(arr[i]);
	}

	cout << endl << "Size of queue = " << iQueue.size() << endl << endl;

	while ( !iQueue.empty() )
	{
		cout << "Back element= " << iQueue.back() ;
		cout << "  Popping " << iQueue.front() << endl;
		iQueue.pop();
	}
}