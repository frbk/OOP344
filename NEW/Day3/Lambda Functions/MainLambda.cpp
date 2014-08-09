#include <iostream>
#include <algorithm>

using namespace std;

/*
Lambda funtions
   [] (in i) {cout << i ;}
have three components:
[]		:= Lambda introducer
(int i)	:= Lambda parameters
{}		:= function body
  
*/

void main()
{
	int arr[] = {7, 3, 6, 1, 8, 4, 9, 5, 2};
	int lenArr = sizeof(arr)/sizeof(arr[0]);

	for_each (arr, arr+lenArr
		    , [] (int i)
	          {
				  if(i%2)
					  cout << i << endl;
	          }
	        );

	int greater3 = 0;
	for_each (arr, arr+lenArr, [&greater3] (int i) {  if(i>3) ++greater3;});
	cout << "There are " << greater3 << " numbers greater then 3." << endl;

	auto display1 = [] (int i, int &count, int chkSum) {  ++count; cout << i << endl; chkSum +=i; return chkSum; };
	int cnt = 0, checkSum = 0;
	for each (int val in arr)
		checkSum = display1(val , cnt, checkSum);
	cout << "There were displayed " << cnt << " numbers.";
	cout << "Check sum = " << checkSum << " numbers.";

	// trailing return type
	bool isEven;
	auto display2 = [] (int i) -> bool {  cout << i; return i%2==0; };
	for each (int val in arr)
	{
		isEven = display2(val);
		cout << " is Even? " << isEven << endl;
	}
}