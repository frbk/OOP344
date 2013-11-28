#include <iostream>
using namespace std;

struct MyClass
{
   int Val;
   MyClass() {cout << "MyClass Constructor Val=" << Val << endl; }
   MyClass(int i) {Val=i; cout << "MyClass Constructor Val=" << Val << endl; }
   ~MyClass() {cout << "MyClass Destructor Val=" << Val << endl; }
   int getVal() { return Val; }
};

// This operator should match the "new (nothrow)" call
/* Error: no matching operator delete found; memory will
   not be freed if initialization throws an exception.
*/
void operator delete (void *p, const std::nothrow_t &)
{
   cout << "In delete" << endl;
   ::delete p;
}


void main()
{
   // Case 1
   cout << "The 'operator new' throws std::bad_alloc when fails" << endl;
   MyClass *p1;
   try {
      p1 = new MyClass;
   } catch ( std::bad_alloc e )
   {
      cout << "std::bad_alloc thrown" << endl;
      return;
   }
   delete p1;

   // Case 2
   cout << endl << "The 'new (nothrow)' operator used in firmware applcatons returns a ZERO pointer when it fails" << endl;
   // We MUST define a pair operator delete for the "new (nothrow)" call.
   MyClass *p2 = new (nothrow) MyClass[1000000000];
//   MyClass *p2 = new (nothrow) MyClass;          // this code works fine
   if (!p2)
   {
      cout << "Fail to allocate memory for *p3" << endl;
//      return;
   }
   else
      delete p2;

   // Case 3
   // Placement "new" operator
   cout << endl << "The 'Placement new' operator used for one object" << endl;
   cout << "I alllocate memory for the object" << endl;
   MyClass *p3 = (MyClass *) operator new (sizeof(MyClass));
   cout << "I create the object and invoke the Constructor" << endl;
   MyClass *pMyClass3 = new (p3) MyClass(9);
   cout << "*p3 = " << p3 << " *pMyClass3 = " << pMyClass3 << endl;
   cout << "Now we delete the allocated memory and the destructor will be called implicetelly" << endl;
   delete p3;

   // Case 4
   // Using "C" style alloc / free memory
   cout << endl << "I alllocate memory for the array of objects. We can use either (new, delete) or (malloc, free)" << endl;
//   MyClass *p4 = reinterpret_cast<MyClass *> (operator new (sizeof(MyClass)*10));
   MyClass *p4 = reinterpret_cast<MyClass *> (malloc(sizeof(MyClass)*10));

   cout << endl << "I create the objects in the array and invoke the Constructor" << endl;
   MyClass *pMyClass4 = p4;
   int i;
   for ( i=0 ; i<10 ; i++, pMyClass4++)
      new (pMyClass4) MyClass(50 + i);

   cout << endl << "Let's dysplay the array just created!" << endl;
   for ( i=0 ; i<10 ; i++ )
      cout << "MyClass[" << i << "].Val=" << p4[i].getVal() << endl;

   cout << endl << "We call explicitelly the destructor of the MyClass object" << endl;
   for ( i=0 ; i<10 ; i++ )
      p4[i].~MyClass();
   cout << "Now we delete the allocated memory using 'free' and NO destructor will be called" << endl;
   free (p4);
}
