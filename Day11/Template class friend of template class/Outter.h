#ifndef OUTTER_H
#define OUTTER_H
#include <iostream>
#include "Inner.h"
using namespace std;

template <class L>
class Outter
{
   int idx;
   L arr[10];
public:
   Outter()
   {
      idx = 0;
      for (int i = 0 ; i<10 ; i++)
         arr[i] = 0;
   }
   /*
   keep the function body in the header file to allow to create
   the function body at the same time when the template <type> is resolved
   */
   void addInnerValue(Inner<L> Inn)  {arr[idx++] = Inn.Value;}

   L operator [] (int i)
   {
      return arr[i];
   }

   friend ostream &operator << (ostream &os, Outter &obj)
   {
      for (int i = 0 ; i<10 ; i++)
         os << obj.arr[i] << ", ";
      os << endl;
      return os;
   }
};

#endif
