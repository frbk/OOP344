#include <iostream>
#include "VisitorClass.h"
#include "AllowOthers.h"
using namespace std;


void VisitorClass::Function1(AllowOthers &o)
{
   cout << "From VisitorClass::Function1 function, AllowOthers.Val=" << o.Val << endl;
}

void VisitorClass::Function2(AllowOthers &o)
{
   cout << "From VisitorClass::Function2 function, AllowOthers.Val=" << o.Val << endl;
}
