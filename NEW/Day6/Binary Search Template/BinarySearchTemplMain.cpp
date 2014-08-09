#include <iostream>
#include "BinarySearchInt.h"
#include "BinarySearchStr.h"
using namespace std;

void main()
{
   int arrInt[] = {1, 4, 6, 8, 9, 11, 15, 17, 19, 21, 24, 25};
   int lengthInt = sizeof(arrInt) / sizeof(int);
   int valInt;
   char *arrStr[] = {"abc", "defg", "hi", "j", "kl"};
   int lengthStr = sizeof(arrStr) / sizeof(char *);
   char valStr[20];
   int i, ret;

   // Searching an array of Integers
   BinarySearchInt  SearchInt(lengthInt, arrInt);

   cout << "Input a number to search: ";
   cin >> valInt;
   ret = SearchInt.Search(valInt);

   for ( i=0 ; i<lengthInt ; i++)
	   cout << arrInt[i] << ", ";
   cout << endl;

   if (ret < 0)
      cout << "The number " << valInt << " was not found in the array.but can be inserted in position " << -ret-1 << endl;
   else
      cout << "The number " << valInt << " was found at the position " << ret << endl;

   // Searching an array of Strings
   BinarySearchStr  SearchStr(lengthStr, arrStr);

   cout << "Input a String to search: ";
   cin >> valStr;
   ret = SearchStr.Search(valStr);

   for ( i=0 ; i<lengthStr ; i++)
	   cout << arrStr[i] << ", ";
   cout << endl;

   if (ret < 0)
      cout << "The number " << valStr << " was not found in the array.but can be inserted in position " << -ret-1 << endl;
   else
      cout << "The number " << valStr << " was found at the position " << ret << endl;
}
