#ifndef TRACEMEMLEAK_H
#define TRACEMEMLEAK_H
#include <stdlib.h>
#include <stdio.h>

class TraceMemLeak
{
public:
   static void Add (void *p, char const *file, int line)
   {
      printf("Alloc: %d  <%s::%d>\n", p, file, line);
   }

   static void Remove(void *p, char const *file="?", int line=0)
   {
      printf("Free: %d  <%s::%d>\n", p, file, line);
   }
};


#endif