#include <iostream>
using namespace std;

int BinarySearch(int val1, unsigned int length, int arr[]);

void main()
{
   int arr[] = {1, 4, 6, 8, 9, 11, 15, 17, 19, 21, 24, 25};
   int length = sizeof(arr) / sizeof(int);
   int val;
   int i;

   cout << "Input a number to search: ";
   cin >> val;
   int ret = BinarySearch(val, length, arr);

   for ( i=0 ; i<length ; i++)
	   cout << arr[i] << ", ";
   cout << endl;

   if (ret < 0)
      cout << "The number " << val << " was not found in the array.but can be inserted in position " << -ret-1 << endl;
   else
      cout << "The number " << val << " was found at the position " << ret << endl;
}


int BinarySearch(int val1, unsigned int length, int arr[])
{
   int first = 0;
   int last = length-1;
   int mid;
   while(first<=last)
   {
      mid = (last+first)/2;
      if (val1<arr[mid])
         last=mid-1;
      else if (val1>arr[mid])
         first=mid+1;
      else
         return mid;
   }
   return -(first + 1);    // failed to find key
}
