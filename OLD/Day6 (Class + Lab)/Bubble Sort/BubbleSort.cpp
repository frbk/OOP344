#include <iostream.h>

void BubbleSort(int Arr[], unsigned int iLen);

void main()
{
   int iArr[] = {6,3,9,2,1,7,4,5};
   int iLen = sizeof(iArr)/sizeof(int);

   cout << "Before sorting :";
   for ( int i = 0 ; i < iLen ; i++ )
      cout << iArr[i] << ",";
   cout << endl;

   BubbleSort(iArr, iLen);

   iLen = sizeof(iArr)/sizeof(int);
   cout << "After sorting :";
   for ( i = 0 ; i < iLen ; i++ )
      cout << iArr[i] << ",";
   cout << endl;
}

void BubbleSort(int Arr[], unsigned int iLen)
{
   int iTemp, flagSwap;
   unsigned int i;

   flagSwap = 1;
   while ( flagSwap )
   {
      flagSwap = 0;
      for ( i=0 ; i < iLen-1 ; i++ )
      {
         if ( Arr[i]>Arr[i+1] )
         {
            iTemp = Arr[i];
            Arr[i] = Arr[i+1];
            Arr[i+1] = iTemp;
            flagSwap = 1;
         }
      }
      iLen--;
   }
}
