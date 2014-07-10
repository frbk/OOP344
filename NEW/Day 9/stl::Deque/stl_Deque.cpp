/*
deque (usually pronounced like "deck") is an irregular acronym of double-ended queue.
 Double-ended queues are a kind of sequence containers. As such, their elements are
 ordered following a strict linear sequence.

Deques may be implemented by specific libraries in different ways, but in all cases
 they allow for the individual elements to be accessed through random access iterators,
 with storage always handled automatically (expanding and contracting as needed).

Deque sequences have the following properties:

Individual elements can be accessed by their position index. 
Iteration over the elements can be performed in any order. 
Elements can be efficiently added and removed from any of its ends (either the beginning
 or the end of the sequence). 


Therefore they provide a similar functionality as the one provided by vectors, but with
 efficient insertion and deletion of elements also at the beginning of the sequence and
 not only at its end. On the drawback side, unlike vectors, deques are not guaranteed to
 have all its elements in contiguous storage locations, eliminating thus the possibility
 of safe access through pointer arithmetics.

Both vectors and deques provide thus a very similar interface and can be used for similar
 purposes, but internally both work in quite different ways: While vectors are very similar
 to a plain array that grows by reallocating all of its elements in a unique block when its
 capacity is exhausted, the elements of a deques can be divided in several chunks of storage,
 with the class keeping all this information and providing a uniform access to the elements.
 Therefore, deques are a little more complex internally, but this generally allows them to
 grow more efficiently than the vectors with their capacity managed automatically, specially
 in large sequences, because massive reallocations are avoided.

For operations that involve frequent insertion or removals of elements at positions other than
 the beginning or the end, deques perform worse and have less consistent iterators and
 references than lists.
*/

#include <iostream>
#include <deque>
using namespace std;


void main()
{
	int arr[] = {4, 7, 2, 9, 5, 3, 8};
	deque<int> iDeque;
	int i, sz;

	sz = sizeof(arr) / sizeof(arr[0]);
	for ( i=0 ; i<sz ; i++)
	{
		cout << "Pushing back " << arr[i] << endl;
		iDeque.push_back(arr[i]);
	}

	cout << endl << "Size of queue = " << iDeque.size() << endl << endl;

	while ( !iDeque.empty() )
	{
		cout << "  Popping back " << iDeque.back() << endl;
		iDeque.pop_back();
	}


	for ( i=0 ; i<sz ; i++)
	{
		cout << "Pushing back " << arr[i] << endl;
		iDeque.push_back(arr[i]);
	}

	cout << endl << "Size of queue = " << iDeque.size() << endl << endl;

	for (i=0 ; i<iDeque.size() ; i++)
		cout << "Dequeue[" << i << "] = " << iDeque[i] << endl;
	cout << endl << endl;

	for (i=0 ; i<iDeque.size() ; i++)
		cout << "Dequeue.at(" << i << ") = " << iDeque.at(i) << endl;
	cout << endl << endl;

	while ( !iDeque.empty() )
	{
		cout << "  Popping front " << iDeque.front() << endl;
		iDeque.pop_front();
	}
}
