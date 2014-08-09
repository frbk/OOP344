#include "ClassA.h"
#include "ClassB.h"

//ClassA ClassB:: obj;  // GOOD: this should be placed in the ClassB.cpp
ClassB  xB;
ClassA ClassB:: obj;  // BAD: this should be placed before "ClassB  xB;" or in the ClassB.cpp
/*
BAD: Static initialization order is incorrect
Output:
=======
ClassB::ctor
ClassA::funcA
ClassA::ctor

FIX: Move the "ClassA ClassB:: obj;" in the ClassB.cpp
ClassA::ctor
ClassB::ctor
ClassA::funcA
*/

void main()
{
}