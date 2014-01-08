/*
Maps are a kind of associative containers that stores elements formed by the
 combination of a key value and a mapped value.

In a map, the key value is generally used to uniquely identify the element,
 while the mapped value is some sort of value associated to this key. Types
 of key and mapped value may differ. For example, a typical example of a map
 is a telephone guide where the name is the key and the telephone number is
 the mapped value.

Internally, the elements in the map are sorted from lower to higher key value
 following a specific strict weak ordering criterion set on construction.

As associative containers, they are especially designed to be efficient accessing
 its elements by their key (unlike sequence containers, which are more efficient
 accessing elements by their relative or absolute position). 

Therefore, the main characteristics of a map as an associative container are:

Unique key values: no two elements in the map have keys that compare equal to
 each other. For a similar associative container allowing for multiple elements
 with equivalent keys, see multimap. 
Each element is composed of a key and a mapped value. For a simpler associative
 container where the element value itself is its key, see set. 
Elements follow a strict weak ordering at all times. Unordered associative arrays,
 like unordered_map, are available in implementations following TR1. 


Maps are also unique among associative containers in that they implement the direct
 access operator (operator[]) which allows for direct access of the mapped value.
*/

#include <iostream>
#include <map>
using namespace std;


void main()
{
	int arr[] = {4, 7, 2, 9, 5, 3, 8};
	map<char,int> cMap;
	map<char,int>::iterator it;
	pair<map<char,int>::iterator,bool> ret;
	int i, sz;

	sz = sizeof(arr) / sizeof(arr[0]);
	for ( i=0 ; i<sz ; i++)
	{
		cout << "Add to Map = <" << ((char)('d'+i)) << "," << arr[i] << ">" << endl;
		cMap[(char)('d'+i)] = arr[i];
	}
	cMap['a'] = 100;
	cMap['c'] = 300;
	cMap['b'] = 200;

	cout << "Size of Map = " << cMap.size() << endl << endl;

	cout << endl << "THe elements are added to the Map in order:" << endl;
	for (it=cMap.begin() ; it != cMap.end() ; it++)
	{
		cout << "<" << it->first << "," << it->second << ">" << endl;
	}
	cout << endl;

	cout << "Add to Map = <b,500>" << endl;
	ret = cMap.insert (pair<char,int>('b',500) ); 
	if ( !ret.second )
	{
		cout << "Element 'b' already existed";
		cout << " with a value of " << ret.first->second << endl;
	}
	cout << endl;

	it=cMap.find('k');
	if (it==cMap.end())
		cout << "Key 'k' not found in the Map." << endl;
	else
		cout << "Key 'k' found in the Map. Value = " << it->second << endl;
	cout << endl;

	it=cMap.find('d');
	if (it==cMap.end())
		cout << "Key 'd' not found in the Map." << endl;
	else
		cout << "Key 'd' found in the Map. Value = " << it->second << endl;
}
