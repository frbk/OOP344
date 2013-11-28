#include <iostream>
using namespace std;

class MyClass
{
   int ID;
public:
   MyClass(int id) {ID = id; }
   int getID() { return ID; }
};

void SelectionSort(MyClass *Arr[], unsigned int iLen);

void main()
{
   MyClass *iArr[8];
   iArr [0] = new MyClass(6);
   iArr [1] = new MyClass(3);
   iArr [2] = new MyClass(9);
   iArr [3] = new MyClass(2);
   iArr [4] = new MyClass(1);
   iArr [5] = new MyClass(7);
   iArr [6] = new MyClass(4);
   iArr [7] = new MyClass(5);

   int iLen = sizeof(iArr)/sizeof(iArr[0]);

   cout << "Before sorting :";
   for ( int i = 0 ; i < iLen ; i++ )
      cout << iArr[i]->getID() << ",";
   cout << endl;

   SelectionSort(iArr, iLen);

   cout << "After sorting :";
   for ( i = 0 ; i < iLen ; i++ )
      cout << iArr[i]->getID() << ",";
   cout << endl;
}


void SelectionSort(MyClass *Arr[], unsigned int iLen)
{
   MyClass *iTemp;
   int iMin;
   unsigned int iFirst, i;
   for ( iFirst=0 ; iFirst < iLen-1 ; iFirst++ )
   {
      iMin = iFirst;
      for ( i=iFirst ; i < iLen ; i++ )
      {
         if ( Arr[iMin]->getID() > Arr[i]->getID() )
         {
            iMin = i;
         }
      }
      iTemp = Arr[iMin];
      Arr[iMin] = Arr[iFirst];
      Arr[iFirst] = iTemp;
   }
}
