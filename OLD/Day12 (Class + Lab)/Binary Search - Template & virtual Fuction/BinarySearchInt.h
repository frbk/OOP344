#ifndef BINARYSEARCHINT_H
#define BINARYSEARCHINT_H
#include "BinarySearchTempl.h"

class BinarySearchInt : public BinarySearchTempl<int>
{
public:
   BinarySearchInt(unsigned int length, int *arr)
      : BinarySearchTempl<int>(length, arr)
   {}

   int Compare(int val1, int val2)
   {
      if (val1<val2)
         return -1;
      else if (val1>val2)
         return 1;
      else
         return 0;
   }
};

#endif
