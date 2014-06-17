#ifndef CASTDERIV_H
#define CASTDERIV_H

#include "CastBase.h"

class CastDeriv : public CastBase
{
public:
   int vDeriv;
   int ciVal;

   CastDeriv(int v) : CastBase(v), ciVal(1)
   {
      vDeriv = v;
   }

   void displayValue()
   {
      cout << "vDeriv= " << vDeriv << endl;
   }

   void changeConstValue()  const
   {
//	  const_cast<int>(ciVal)  = ciVal + 1;
      cout << "ciVal= " << ciVal << endl;
   }
};

#endif
