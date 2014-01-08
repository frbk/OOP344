/*
Vectors are a kind of sequence containers. As such, their elements are ordered following a strict linear sequence.

Vector containers are implemented as dynamic arrays; Just as regular arrays, vector containers have their elements
 stored in contiguous storage locations, which means that their elements can be accessed not only using iterators
 but also using offsets on regular pointers to elements.

But unlike regular arrays, storage in vectors is handled automatically, allowing it to be expanded and contracted as needed.

Vectors are good at:

Accessing individual elements by their position index (constant time). 
Iterating over the elements in any order (linear time). 
Add and remove elements from its end (constant amortized time). 


Compared to arrays, they provide almost the same performance for these tasks, plus they have the ability to be easily
 resized. Although, they usually consume more memory than arrays when their capacity is handled automatically (this
 is in order to accomodate for extra storage space for future growth).

Compared to the other base standard sequence containers (deques and lists), vectors are generally the most efficient
 in time for accessing elements and to add or remove elements from the end of the sequence. For operations that
 involve inserting or removing elements at positions other than the end, they perform worse than deques and lists
 , and have less consistent iterators and references than lists.

Internally, vectors -like all containers- have a size, which represents the amount of elements contained in the vector
. But vectors, also have a capacity, which determines the amount of storage space they have allocated, and which can be
 either equal or greater than the actual size. The extra amount of storage allocated is not used, but is reserved for
 the vector to be used in the case it grows. This way, the vector does not have to reallocate storage on each occasion
 it grows, but only when this extra space is exhausted and a new element is inserted (which should only happen in
 logarithmic frequence in relation with its size).

Reallocations may be a costly operation in terms of performance, since they generally involve the entire storage space
 used by the vector to be copied to a new location. Therefore, whenever large increases in size are planned for a vector,
 it is recommended to explicitly indicate a capacity for the vector using member function vector::reserve.
*/

#include <iostream>
#include <vector>
using namespace std;


void main()
{
	vector<int> iVect;
	vector<int>::iterator it;
	int i;

	iVect.push_back(3);
	iVect.push_back(5);
	iVect.push_back(6);
	iVect.push_back(1);
	iVect.push_back(9);
	iVect.push_back(4);
	iVect.push_back(9);
	vector<int>::size_type sz = iVect.size();
	for ( i = 0 ; i < sz ; i++ )
		cout << iVect[i] << ", ";
	cout << endl << endl;
	cout << "Capacity=" << iVect.capacity() << endl;
	cout << "Size=" << iVect.size() << endl;

	cout << "Front element=" << iVect.front() << endl;
	cout << "Back element=" << iVect.back() << endl;
	iVect.pop_back();
	cout << "Back element after pop_back()=" << iVect.back() << endl;
	cout << "Element at(2)=" << iVect.at(2) << endl;
	cout << "Element [2]=" << iVect[2] << endl;

	cout << endl << "Reserving space for 50 elements:" << endl;
	iVect.reserve(50);
	it = iVect.begin();
	it+=3;
	cout << "Inserting before the element at posisition 3 four elements 100" << endl;
	iVect.insert(it, 4, 100);
	sz = iVect.size();
	for ( i = 0 ; i < sz ; i++ )
		cout << iVect[i] << ", ";
	cout << endl << endl;

	cout << "Capacity=" << iVect.capacity() << endl;
	cout << "Size=" << iVect.size() << endl << endl;

	cout << "Erase elements from index 4 to index 7 inclusively:" << endl;
	iVect.erase(iVect.begin()+4, iVect.begin()+ 7 + 1);
	sz = iVect.size();
	for ( i = 0 ; i < sz ; i++ )
		cout << iVect[i] << ", ";
	cout << endl << endl;

	cout << "Erase elements from index 4 to the end:" << endl;
	iVect.erase(iVect.begin()+4, iVect.end() );
	sz = iVect.size();
	for ( i = 0 ; i < sz ; i++ )
		cout << iVect[i] << ", ";
	cout << endl << endl;
	cout << "Capacity=" << iVect.capacity() << endl;
	cout << "Size=" << iVect.size() << endl << endl;

	cout << "Reading by reverse iterator:" << endl;
	vector<int>::reverse_iterator rit;
	for ( rit=iVect.rbegin() ; rit < iVect.rend(); ++rit )
		cout << *rit << ", ";
	cout << endl << endl;


	cout << "Clear the vector:" << endl;
	iVect.clear();
	cout << "Capacity=" << iVect.capacity() << endl;
	cout << "Size=" << iVect.size() << endl << endl;
}