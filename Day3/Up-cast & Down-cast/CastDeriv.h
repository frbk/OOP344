#ifndef CASTDERIV_H
#define CASTDERIV_H

#include "CastBase.h"

class CastDeriv : public CastBase
{
public:
   int vDeriv;
   CastDeriv(int v) : CastBase(v)
   {
      vDeriv = v;
   }

   void displayValue()
   {
      cout << "vDeriv= " << vDeriv << endl;
   }
};

#endif
