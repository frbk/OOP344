#ifndef ALLOWOTHERS_H
#define ALLOWOTHERS_H
#include "VisitorMember.h"
#include "VisitorClass.h"
class AllowOthers
{
   int Val;
public:
   AllowOthers(int i) { Val=i; }
   friend void VisitorMember::VisitorFunction(AllowOthers &o);
   friend VisitorClass;
};

#endif
