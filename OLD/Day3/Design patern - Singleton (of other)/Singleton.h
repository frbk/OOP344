#ifndef SINGLETON_H
#define SINGLETON_H
#include "Universe.h"

class Singleton
{
   Singleton() {}
   static Universe *inst;

 public:
   static Universe *getInstance()
   {
      if ( inst == 0 )
      {
         inst = new Universe;
      }
      return inst;
   }
};

#endif