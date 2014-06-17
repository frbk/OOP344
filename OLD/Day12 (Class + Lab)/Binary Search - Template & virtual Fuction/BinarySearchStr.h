#ifndef BINARYSEARCHSTR_H
#define BINARYSEARCHSTR_H
#include "BinarySearchTempl.h"

class BinarySearchStr : public BinarySearchTempl<char *>
{
public:
   BinarySearchStr(unsigned int length, char **arr)
      : BinarySearchTempl<char *>(length, arr)
   {}

   int Compare(char *val1, char *val2)
   {
      if (val1==0)
         return -1;
      else if (val2==0)
         return 1;
      else
         return strcmp(val1, val2);
   }
};

#endif
