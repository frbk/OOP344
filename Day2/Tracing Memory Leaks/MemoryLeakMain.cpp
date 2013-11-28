#include <iostream>
#include "LeakingClass.h"
using namespace std;

#ifndef NDEBUG
#include "TraceMemLeak.h"

void *operator new (size_t size, char const * file, int line)
{
    void * p = malloc (size);
    TraceMemLeak::Add (p, file, line);
    return p;
}

void operator delete (void * p, char const * file, int line)
{
   TraceMemLeak::Remove (p, file, line);
   free (p);
}

void * operator new (size_t size)
{
   void * p = malloc (size);
   TraceMemLeak::Add (p, "?", 0);
   return p;
}

void operator delete (void * p)
{
   TraceMemLeak::Remove (p);
   free (p);
}
#define new new(__FILE__, __LINE__)

#endif


void main()
{

#ifdef NDEBUG
   cout << "Release Version." << endl;
#else
   cout << "Debug Version." << endl;
#endif
   {
      cout << "Line= " << __LINE__ << endl;
      LeakingClass  cls1("Memory on Heap");
      int i = 0;
      int j = 1;
      {
         LeakingClass  *cls2 = new LeakingClass("Class on the Heap");
         LeakingClass  cls3("To be overwritten");
//         cls3 = *cls2;
         delete cls2;
      }
      int k = 2;
      LeakingClass  cls4("Other Memory on Heap");
   }
}
