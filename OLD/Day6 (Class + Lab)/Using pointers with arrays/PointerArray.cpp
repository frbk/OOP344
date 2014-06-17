#include <iostream>
using namespace std;

int main()
{
   // the array represents a sequence of same type variables
   int array[8]={1,2,3,4,5,6,7, 8};
   int i;
   int *pi;
   cout << "Normal printing" << endl;
   for( i=0 ; i < 8 ; i++ )
      cout << array[i] << ", ";
   cout << endl;

   cout << "Pointer used in printing array using counter:" << endl;
   for (pi=&array[0] , i=0 ; i<8 ; i++, pi++)
   { 
      cout << *pi << ", ";
   }
   cout << endl;

   cout << "Pointer used in printing array using last address of the array:" << endl;
   int *piLast;
   for (pi=&array[0], piLast = pi + 8 ; pi<piLast ; pi++)
   { 
      cout << *pi << ", ";
   }
   cout << endl;

   cout << "Displaying an integer array using a short pointer:" << endl;
   short *ps = reinterpret_cast<short *>(&array[0]);
   for (i=0 ; i<8*2 ; i++, ps++)
   { 
      cout << *ps << ", ";
   }
   cout << endl;

   cout << "Displaying an integer array using a char pointer:" << endl;
   char *pc = reinterpret_cast<char *>(&array[0]);
   for (i=0 ; i<8*4 ; i++, pc++)
   { 
      cout << (short ) *pc << ", ";
   }
   cout << endl;

   return (0);
}
