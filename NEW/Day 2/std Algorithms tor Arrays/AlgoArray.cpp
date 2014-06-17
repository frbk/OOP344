#include <algorithm>
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
	int arr2[100];
	int len = sizeof(arr)/sizeof(arr[0]);

	copy(arr, arr+len, arr2);
	sort(arr2, arr2+len);
	for (int i=0 ; i<len ; i++)
		cout << arr2[i] << ',';
	cout << endl;

	int *p2=unique(arr2, arr2+len);
	int len2 = p2-arr2;
	for (int i=0 ; i<len2 ; i++)
		cout << arr2[i] << ',';
	cout << endl;

	reverse(arr, arr+len);
	for (int i=0 ; i<len ; i++)
		cout << arr[i] << ',';
	cout << endl;

	int *p = min_element(arr, arr+len);
	cout << "min element=" << *p << endl;
	p = max_element(arr, arr+len);
	cout << "MAX element=" << *p << endl;

	int val = count(arr, arr+len,5);
	cout << "number 5 occurs " << val << " time(s)" << endl;

	val = count_if(arr, arr+len, Greater5);
	cout << "There are " << val << " numbers Greater than 5" << endl;

	p=arr-1;
	val=5;
	while((p = find(p+1, arr+len, val)) != arr+len)
	{
		cout << "arr[" << p-arr << "] = " << val << endl;
	}

	p=arr-1;
	while((p = find_if(p+1, arr+len, Greater5)) != arr+len)
	{
		cout << "arr[" << p-arr << "] > " << val << endl;
	}

	p=arr-1;
	while((p = find_if(p+1, arr+len, Greater5Cls())) != arr+len)
	{
		cout << "arr[" << p-arr << "] > " << val << "  (using function object)" << endl;
	}

	// with Referenced parameter in Display::operator() allow modification of the array
	for_each(arr, arr+len, Display);
	for (int i=0 ; i<len ; i++)
		cout << arr[i] << ',';
	cout << endl;
}
