#include <iostream>
#include "VisitorMember.h"
#include "AllowOthers.h"
using namespace std;

void VisitorMember::VisitorFunction(AllowOthers &o)
{
   cout << "From VisitorFunction function, AllowOthers.Val=" << o.Val << endl;
}
