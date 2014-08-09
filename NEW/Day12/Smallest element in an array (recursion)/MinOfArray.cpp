#include <iostream>
using namespace std;

unsigned int MinOfArrayLoop(int [], unsigned int);
unsigned int MinOfArrayRecursive(int [], unsigned int);


void main()
{
   int Arr[] = {7, 16, 9, 6, 12, 4, 15, 8};
   unsigned int min;
   unsigned int len = sizeof(Arr) / sizeof(Arr[0]);

   min = MinOfArrayLoop(Arr, len);
   cout << "Through Loop algorithm the smallest element of the array is " << Arr[min] << " at index " << min << endl;

   min = MinOfArrayRecursive(Arr, len);
   cout << "Through Recursive algorithm the smallest element of the array is " << Arr[min] << " at index " << min << endl;
}

unsigned int MinOfArrayLoop(int Arr[], unsigned int length)
{
   unsigned int minIdx;
   for (int i=minIdx=0 ; i<length ; i++)
      if (Arr[i] < Arr[minIdx])
         minIdx = i;

   return minIdx;
}

unsigned int MinOfArrayRecursive(int Arr[], unsigned int length)
{
   if (length == 1)
      return 0;
   unsigned int minIdx;
   minIdx = MinOfArrayRecursive(Arr, length - 1);
   if (Arr[length-1] < Arr[minIdx])
      minIdx = length-1;

   return minIdx;
}
