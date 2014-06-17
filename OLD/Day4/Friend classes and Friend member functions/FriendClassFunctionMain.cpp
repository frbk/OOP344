#include <iostream>
#include "VisitorClass.h"
#include "VisitorMember.h"
#include "AllowOthers.h"
using namespace std;

void main()
{
   AllowOthers all(13);
   VisitorMember vm;
   vm.VisitorFunction(all);

   VisitorClass vc;
   vc.Function1(all);
   vc.Function2(all);
}
