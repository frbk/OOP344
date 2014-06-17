#include <stdio.h>
#include <iostream>
using namespace std;

int compareInt(const void *val1, const void *val2)
{
   int v1, v2;
   v1 = *reinterpret_cast<const int *>(val1);
   v2 = *reinterpret_cast<const int *>(val2);
   if (v1 < v2)
      return -1;
   else if (v1 > v2)
      return 1;
   else
      return 0;
}

int compareStr(const void *val1, const void *val2)
{
   const char *v1, *v2;

   v1 = *(char **)val1;
   v2 = *(char **)val2;
   return strcmp(v1, v2);
}

void main()
{
   // Sorting an array of integers
   int arrInt[] = {6, 2, 8, 4, 1, 7, 4, 9, 3};
   int length = sizeof(arrInt) / sizeof(arrInt[0]);
   int i;
   cout << "arrInt before sorting:" << endl;
   for (i=0 ; i<length ; i++)
      cout << arrInt[i] << ", ";
   cout << endl;
   qsort(arrInt, length, sizeof(arrInt[0]), compareInt);

   cout << "arrInt after sorting:" << endl;
   for (i=0 ; i<length ; i++)
      cout << arrInt[i] << ", ";
   cout << endl << endl;


   // Sorting an array of strings
   char *arrStr[] = {"hij", "klm", "abc", "opq", "defg"};
   length = sizeof(arrStr) / sizeof(arrStr[0]);
   cout << "arrStr before sorting:" << endl;
   for (i=0 ; i<length ; i++)
      cout << arrStr[i] << ", ";
   cout << endl;
   qsort(arrStr, length, sizeof(arrStr[0]), compareStr);

   cout << "arrStr after sorting:" << endl;
   for (i=0 ; i<length ; i++)
      cout << arrStr[i] << ", ";
   cout << endl;
}
