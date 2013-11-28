#include <iostream>
#include "NewDeleteForClass.h"
using namespace std;

const unsigned int MyClass::pool_size = 10;
char MyClass::pool_map[MyClass::pool_size] = {0};
char MyClass::pool[MyClass::pool_size * sizeof(MyClass)] = {0};

// The size is not used instead we calculate it using sizeof
void* MyClass::operator new(size_t /*sz*/) throw(bad_alloc)
{
   int i;
   for( i = 0 ; i < pool_size ; i++)
   {
      if(!pool_map[i])
      {
         int offset = i * sizeof(MyClass);
         cout << "block[" << i << "]=" << (void *)(pool + offset) << "  ";
         pool_map[i] = 1;
         return pool + offset;
      }
   }
   cout << "out of memory" << endl;
   throw bad_alloc();
}

void MyClass::operator delete(void* m)
{
   if(!m) return; // check for null pointer
   // calculate which block number number in the pool is:
   unsigned long block = ((unsigned long)m - (unsigned long)pool ) / sizeof(MyClass);
   cout << "mark as free pool block " << block << endl;
   pool_map[block] = 0;
}

MyClass *MyClass::getPointer(int i)
{
   if (!pool_map[i])
      return 0;
   int offset = i * sizeof(MyClass);
   return reinterpret_cast<MyClass *>(pool + offset);
}


void main()
{
   int i;
   MyClass *p[MyClass::pool_size];
   for (i=0 ; i<MyClass::pool_size ; i++)
      p[i] = new MyClass(i*3);
   cout << "p[3]->Val = " << p[3]->getVal() << "  Address=" << p[3] << endl;
   delete p[3];
   p[3] = new MyClass(100);
   cout << "p[3]->Val = " << p[3]->getVal() << "  Address=" << p[3] << endl;

   try {
      MyClass *pOutOfMemory = new MyClass(99);
   }
   catch (bad_alloc)
   {
      cout << "Bad_alloc caught !" << endl;
   }

   // another way to access the elements in the POOL
   MyClass *pClass;
   for (i=0 ; i<MyClass::pool_size ; i++)
   {
      pClass = MyClass::getPointer(i);
      if (pClass)
         cout << "POOL[" << i << "]=" << pClass->getVal() << endl;
      delete p[i];
   }
}
