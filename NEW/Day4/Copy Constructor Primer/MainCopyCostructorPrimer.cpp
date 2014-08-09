#include <iostream>
#include "MyDerived.h"

using namespace std;

void main()
{
	// Review of using the copy constructor
	MyDerived a(2);
	MyDerived b(a);
	cout << "b.MyBase::val=" << b.MyBase::getVal() << endl;
	cout << "b.derived_val=" << b.getVal() << endl;
}
