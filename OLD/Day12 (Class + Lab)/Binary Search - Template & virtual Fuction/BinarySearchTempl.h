#ifndef BINARYSEARCHTEMPL_H
#define BINARYSEARCHTEMPL_H

template <class T>
class BinarySearchTempl
{
   T *arr;
   unsigned int length;

public:
   BinarySearchTempl(unsigned int length, T *arr)
   {
      this->arr = arr;
      this->length = length;
   }

   int Search(T val1)
   {
      int first = 0;
      int last = length-1;
      int mid;
      while(first<=last)
      {
         mid = (last+first)/2;
         if ( Compare(val1, arr[mid])<0 )
            last=mid-1;
         else if ( Compare(val1, arr[mid])>0 )
            first=mid+1;
         else
            return mid;
      }
      return -(first + 1);    // failed to find key
   }

   virtual int Compare(T val1, T val2) = 0;
};

#endif
