/*
1) Place a breakpoint at the indicated locations
2) run the program in debug mode
3) watch how the new/delete operators are executed
*/
#include <iostream>
using namespace std;

void* operator new(size_t sz) {
  printf("\n   operator new: %d Bytes\n", sz);
// place a breakpoint here
  void* m = malloc(sz);
  if(!m) printf("\n   out of memory");
  return m;
}

void* operator new [](size_t sz) {
  printf("\n   operator new []: %d Bytes\n", sz);
// place a breakpoint here
  void* m = malloc(sz);
  if(!m) printf("\n   out of memory");
  return m;
}

void operator delete(void* m) {
  printf("\n operator delete\n");
// place a breakpoint here
  free(m);
}

void operator delete [](void* m) {
  printf("\n operator delete []\n");
// place a breakpoint here
  free(m);
}

class MyClass
{
   int Val;
public:
   MyClass()
   {
      Val=12;
      cout << "MyClass Def. Costructor Val=" << Val << endl;
   }
   MyClass(int i)
   {
      Val=i;
      cout << "MyClass Costructor Val=" << Val << endl;
   }
   ~MyClass()
   {
      cout << "~MyClass Destructor Val=" << Val << endl;
   }
   int getVal() {return Val;}
};

void main()
{
// place a breakpoint here
   int *pInt = new int(23);
   cout << "*pInt=" << *pInt << endl;
   delete pInt;

   MyClass *pObj = new MyClass(34);
   cout << "pObj->Val=" << pObj->getVal() << endl;
   delete pObj;

   MyClass *pArr = new MyClass[4];
   for (int i=0 ; i<4 ; i++)
      cout << "pArr[" << i << "]="<< pArr[i].getVal() << endl;
   delete [] pArr;
}
