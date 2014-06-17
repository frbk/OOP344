#ifndef NewDeleteForClass_H
#define NewDeleteForClass_H

#include <iostream>
using namespace std;

class MyClass
{
   int Val;
   static char pool_map[];
   static char pool[];
public:
   static const unsigned int pool_size;
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
   void* operator new(size_t) throw(bad_alloc);
   void operator delete(void*);
   static MyClass *getPointer(int index);
};

#endif
