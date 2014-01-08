/*
Lists are a kind of sequence containers. As such, their elements are ordered following a linear sequence.

List containers are implemented as doubly-linked lists; Doubly linked lists can store each of the elements they contain
 in different and unrelated storage locations. The ordering is kept by the association to each element of a link to
 the element preceding it and a link to the element following it.

This provides the following advantages to list containers:

Efficient insertion and removal of elements anywhere in the container (constant time). 
Efficient moving elements and block of elements within the container or even between different containers (constant time). 
Iterating over the elements in forward or reverse order (linear time). 

Compared to other base standard sequence containers (vectors and deques), lists perform generally better in inserting,
 extracting and moving elements in any position within the container, and therefore also in algorithms that
 make intensive use of these, like sorting algorithms.

The main drawback of lists compared to these other sequence containers is that they lack direct access to the
 elements by their position; For example, to access the sixth element in a list one has to iterate from a known
 position (like the beginning or the end) to that position, which takes linear time in the distance between
 these. They also consume some extra memory to keep the linking information associated to each element (which
 may be an important factor for large lists of small-sized elements).

Storage is handled automatically by the class, allowing lists to be expanded and contracted as needed.
*/
#include <iostream>
#include <list>
using namespace std;


void main()
{
	list<int> iList;
	list<int>::iterator it;
	iList.push_front(1);
	iList.push_front(2);
	iList.push_front(3);
	iList.push_back(101);
	iList.push_back(102);
	iList.push_back(103);
	iList.push_back(102);
	iList.push_back(106);
	iList.push_back(108);
	iList.push_back(120);

	it = iList.begin();
	it++;
	it++;
	it++;
	iList.insert(it,10);
	for (it=iList.begin() ; it!=iList.end() ; it++)
	{
		cout << *it << ", ";
	}
	cout  << endl;

	cout  << "After sorting:" << endl;
	iList.sort();
	for (it=iList.begin() ; it!=iList.end() ; it++)
	{
		cout << *it << ", ";
	}
	cout  << endl << endl;

	cout  << "Scan Backwards:" << endl;
	list<int>::reverse_iterator rit;
	for (rit=iList.rbegin() ; rit!=iList.rend() ; rit++)
	{
		cout << *rit << ", ";
	}
	cout  << endl << endl;

	it = iList.begin();
	it++;
	it++;
	list<int>::iterator it2 = it;
	it2++;
	it2++;
	cout << "Remove elements from [2,4):" << endl;
	iList.erase(it, it2);
//	cout << "it=" << *it << endl;	after erase, first iterator becoms unavailable
	cout << "it2=" << *it2 << endl;
	for (it=iList.begin() ; it!=iList.end() ; it++)
	{
		cout << *it << ", ";
	}
	cout  << endl << endl;

	cout << "Remove duplicated elements:" << endl;
	iList.unique();
	for (it=iList.begin() ; it!=iList.end() ; it++)
	{
		cout << *it << ", ";
	}
	cout  << endl << endl;

	cout << "First element in the List==" <<  iList.front() << endl;
	cout << "Last element in the List==" <<  iList.back() << endl;
	cout  << endl << endl;

	cout << "Size of List=" <<  iList.size() << endl;
	cout << "MAX Size of List=" <<  iList.max_size() << endl;

	list<int> iList2;
	iList2.push_front(501);
	iList2.push_front(502);
	iList2.push_front(503);
	iList2.push_front(504);
	iList2.sort();
	cout << "Ilist2 sorted:" << endl;
	for (it=iList2.begin() ; it!=iList2.end() ; it++)
	{
		cout << *it << ", ";
	}
	cout  << endl << endl;

	cout << "Merging iList with iList2:" << endl;
	iList.merge(iList2);
	iList2.push_back(505);
	for (it=iList.begin() ; it!=iList.end() ; it++)
	{
		cout << *it << ", ";
	}
	cout  << endl << endl;

}
