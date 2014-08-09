#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;


bool Greater5(int i) {return i>5; }
struct Greater5Cls
{
	bool operator()(int i) {return i>5; }
};

struct DisplayForEach
{
	static int cnt;
	// Reference parameter 
	void operator()(int &i) { cout << "for_each: arr[" << cnt++ << "] = " << i++ << endl;}
} Display;
int DisplayForEach::cnt;

void main()
{
	int arr[] = {5,2,8,4,9,1,5,2,6,4};
	int len = sizeof(arr)/sizeof(arr[0]);
	vector<int> vec(arr, arr+len);
	vector<int> vec2(len);
	vector<int>::iterator p;
	vector<int>::iterator p2;

	copy(vec.begin(), vec.end(), vec2.begin());
	sort(vec2.begin(), vec2.end());
	for (int i=0 ; i<len ; i++)
		cout << vec2[i] << ',';
	cout << endl;

	p2 = unique(vec2.begin(), vec2.end());
	for (p=vec2.begin() ; p!= p2 ; p++)
		cout << *p << ',';
	cout << endl;

	reverse(vec.begin(), vec.end());
	for (int i=0 ; i<len ; i++)
		cout << vec[i] << ',';
	cout << endl;

	p = min_element(vec.begin(), vec.end());
	cout << "min element=" << *p << endl;
	p = max_element(vec.begin(), vec.end());
	cout << "MAX element=" << *p << endl;

	int val = count(vec.begin(), vec.end(), 5);
	cout << "number 5 occurs " << val << " time(s)" << endl;

	val = count_if(vec.begin(), vec.end(), Greater5);
	cout << "There are " << val << " numbers Greater than 5" << endl;

	p=vec.begin();
	val=5;
	int idx=0;
	while((p = find(p, vec.end(), val)) != vec.end())
	{
		cout << "arr[" << idx << "] = " << val << endl;
		++p;
		++idx;
	}

	p=vec.begin();
	idx=0;
	while((p = find_if(p, vec.end(), Greater5)) != vec.end())
	{
		cout << "arr[" << idx << "] > " << val << endl;
		++p;
		++idx;
	}

	p=vec.begin();
	idx=0;
	while((p = find_if(p, vec.end(), Greater5Cls())) != vec.end())
	{
		cout << "arr[" << idx << "] > " << val << "  (using function object)" << endl;
		++p;
		++idx;
	}

	// with Referenced parameter in Display::operator() allow modification of the Vector
	for_each(vec.begin(), vec.end(), Display);
	for (int i=0 ; i<len ; i++)
		cout << vec[i] << ',';
	cout << endl;
}
