#include <iostream>
using namespace std;

void SelectionSort(int Arr[], unsigned int iLen);

void main()
{
   int iArr[] = {6,3,9,2,1,7,4,5};
   int iLen = sizeof(iArr)/sizeof(iArr[0]);
   int i;

   cout << "Before sorting :";
   for ( i = 0 ; i < iLen ; i++ )
      cout << iArr[i] << ",";
   cout << endl;

   SelectionSort(iArr, iLen);

   cout << "After sorting :";
   for ( i = 0 ; i < iLen ; i++ )
      cout << iArr[i] << ",";
   cout << endl;
}


void SelectionSort(int Arr[], unsigned int iLen)
{
   int iMin, iTemp;
   unsigned int iFirst, i;
   for ( iFirst=0 ; iFirst < iLen-1 ; iFirst++ )
   {
      iMin = iFirst;
      for ( i=iFirst ; i < iLen ; i++ )
      {
         if ( Arr[iMin]>Arr[i] )
         {
            iMin = i;
         }
      }
      iTemp = Arr[iMin];
      Arr[iMin] = Arr[iFirst];
      Arr[iFirst] = iTemp;
   }
}
