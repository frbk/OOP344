#include "LeakingClass.h"
#include <string.h>

#ifndef NDEBUG
#include "TraceMemLeak.h"

void *operator new (size_t size, char const * file, int line);
void operator delete (void * p, char const * file, int line);
void * operator new (size_t size);
void operator delete (void * p);

#define new new(__FILE__, __LINE__)

#endif

LeakingClass::LeakingClass()
{
   szArr = 0;
}

LeakingClass::LeakingClass(char *sz)
{
   szArr = new char[strlen(sz)+1];
   strcpy(szArr, sz);
}

LeakingClass::~LeakingClass()
{
   // Here we simulate the ommission of the delete statement
   //delete szArr;
}

LeakingClass &LeakingClass::operator =(LeakingClass &o)
{
   // Here we simulate the ommission of the delete statement
   //delete szArr;
   szArr = new char[strlen(o.szArr)+1];
   strcpy(szArr, o.szArr);
   return *this;
}
