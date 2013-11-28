#ifndef CASTBASE_H
#define CASTBASE_H

#include <iostream>
using namespace std;

class CastBase
{
public:
   int vBase;
   CastBase(int v) { vBase = v; }
   virtual void displayValue()
   {
      cout << "vBase= " << vBase << endl;
   }
};

#endif
