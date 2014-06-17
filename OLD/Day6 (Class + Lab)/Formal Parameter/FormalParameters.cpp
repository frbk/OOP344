#include <iostream.h>
#include <string.h>

struct MyClass
{
   void addToVal(int Val)
   {
      Val = Val + 5;
   }

   void addToAddress(int *Val)
   {
      *Val = *Val + 5;
   }

   void addToReference(int &Val)
   {
      Val = Val + 5;
   }

   void useArray(int arr[], int SwapA, int SwapB)
   {
      cout << "sizeof('array formal parameter') is the size of a pointer NOT of the Array = "
           << sizeof(arr) << endl;
      int tmp;
      tmp = arr[SwapA];
      arr[SwapA] = arr[SwapB];
      arr[SwapB] = tmp;
   }
};

int main()
{
   int i;
   MyClass cls;
   int Val;

   Val = 10;
   cout << "Value=" << Val;
   cls.addToVal(Val);
   cout << " After addToVal: Value=" << Val << endl;

   Val = 10;
   cout << "Value=" << Val;
   cls.addToAddress(&Val);
   cout << " After addToAddress: Value=" << Val << endl;

   Val = 10;
   cout << "Value=" << Val;
   cls.addToReference(Val);
   cout << " After addToReference: Value=" << Val << endl;

   // Accessing Arrays
   int Array[] = {0,1,2,3,4,5,6,7,8};
   cout << "Size of the Array = " << sizeof(Array)/sizeof(int) << endl;
   cout << "Initial Array" << endl;
   for (i=0 ; i<sizeof(Array)/sizeof(int) ; i++ )
      cout << Array[i] << ", ";
   cout << endl;

   cout << "Array with First-Last elements swapped" << endl;
   cls.useArray(Array, 2, 5);
   for ( i=0 ; i<sizeof(Array)/sizeof(int) ; i++ )
      cout << Array[i] << ", ";
   cout << endl;

   return (0);
}

