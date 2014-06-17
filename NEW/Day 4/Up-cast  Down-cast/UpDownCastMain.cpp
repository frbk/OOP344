#include "CastDeriv.h"

// Compile with /GR option for RTTI support for Visual C++ compiler
// Compile with -qrtti=all option for RTTI support for Unix IBM cc compiler

void main()
{
	int *p = 0;
	int &rp = *p;  // C++ standard consider illegal a reference to be NULL
//	cout << rp;    // program crashes here
   CastDeriv d1(1);
   CastBase b1 = d1;       // Only the Base class from CastDeriv is copied into CastBase
   cout << "Only the Base class from CastDeriv is copied:" << endl;
   b1.displayValue();
   CastBase *pb1a = &b1;
   pb1a->displayValue();

   CastBase *pb1b = &d1;    // Up Cast
   cout << "Up-Cast to 'pb1b' succeds (polymorphism):" << endl;
   pb1b->displayValue();

   /*
   We know that the base class pointer points to a certain Derved class type
   We can use then either STATIC_AST or REINTERPRET_CAST
   */
   CastDeriv *pDer1 = static_cast<CastDeriv *>(pb1b);
   CastDeriv *pDer2 = reinterpret_cast<CastDeriv *>(pb1b);

   /*
   Here we attempt to make a conversion between pointers to ob jects that are not related
   In this case only REINTERPRET_CAST works
   */
   //int *pInt1  = static_cast<int *>(pb1b);      // invalid type conversion
   int *pInt21  = reinterpret_cast<int *>(pb1b);

   CastBase cb1 = d1;       // Up Cast
   cb1.displayValue();
   CastBase cb2 = static_cast<CastBase>(d1);       // Up Cast
   cb2.displayValue();


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

   const int cVal = 10;
   cout << "const int cVal = " << cVal << endl;
   const int * pcVal = &cVal;
//   *pcVal = 11;  // ERROR: cannot change a const variable
//   int *pVal = pcVal;  // const int * cannot initialize a int *
   int *pVal = const_cast<int *>(pcVal);  // const int * cannot initialize a int *
   *pVal = 11;
}
