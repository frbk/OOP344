#include "CastDeriv.h"

// Compile with /GR option for RTTI support for Visual C++ compiler
// Compile with -qrtti=all option for RTTI support for Unix IBM cc compiler

void main()
{
   CastDeriv d1(1);
   CastBase b1 = d1;       // Only the Base class from CastDeriv is copied into CastBase
   cout << "Only the Base class from CastDeriv is copied:" << endl;
   b1.displayValue();
   CastBase *pb1a = &b1;
   pb1a->displayValue();

   CastBase *pb1b = &d1;    // Up Cast
   cout << "Up-Cast to 'pb1b' succeds (polymorphism):" << endl;
   pb1b->displayValue();

   CastBase b2(2);
   CastDeriv *pd2a;
//   pd2a = &b2;    // Error: NO default Down-Cast
   pd2a = dynamic_cast<CastDeriv *>(&b2);
   if (pd2a)
   {
      cout << "Down-Cast to 'pd2a' succeded:" << endl;
      pd2a->displayValue();
   }
   else
      cout << "Down-Cast failed from a strict Base object to Derived pointer !" << endl;

   CastDeriv *pd2b = dynamic_cast<CastDeriv *>(pb1b);
   if (pd2b)
   {
      cout << "Down-Cast to 'pd2b' succeded:" << endl;
      pd2b->displayValue();
   }
}
