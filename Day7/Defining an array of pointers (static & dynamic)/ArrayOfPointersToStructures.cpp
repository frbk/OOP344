#include <iostream>

#define  DYNAMIC_ARRAY

using namespace std;


class MyClass
{
   int ObjId;

public:
   MyClass(int i)
   {
      ObjId=i;
	  cout << "Constructor=" << ObjId << endl;
   }

   int getObjId(void)
   {
      return ObjId;
   }


   ~MyClass()
   {
      cout << "Destructor=" << ObjId  << endl;
   }
};


int main()
{
   const int Length=3;
   int i;

#ifdef  DYNAMIC_ARRAY
   MyClass **cls;
   cls = new (MyClass *[Length]);
   cout << "We use Dynamic allocation for array of pointers" << endl;
#else
   MyClass *cls[Length];
   cout << "We use Static allocation for array of pointers" << endl;
#endif

   for ( i= 0 ; i<Length ; i++ )
   {
      cls[i] = new MyClass(i);
   }

   for ( i= 0 ; i<Length ; i++ )
   {
         cout << cls[i]->getObjId() << endl;
   }

   for ( i= 0 ; i<Length ; i++ )
   {
      delete cls[i];
   }

#ifdef  DYNAMIC_ARRAY
   delete [] cls;
#endif

   return (0);
}

