#include <iostream>
#include "MyDerived.h"

MyBase *aFunction(MyBase *p);

using namespace std;

void main()
{
	// We present the benchmark of the exercise
	MyDerived a(2);
	MyDerived b(a);
	cout << "b.MyBase::val=" << b.MyBase::getVal() << endl;
	cout << "b.derived_val=" << b.getVal() << endl;

	MyBase *c = aFunction(&a);
	cout << "c->MyBase::val=" << c->MyBase::getVal() << endl;
	cout << "c->derived_val=" << c->getVal() << endl;
}


MyBase *aFunction(MyBase *p)
{
	// We have to create a copy of the object pointed by the base class pointer
	MyBase *tmp = p->getCopy();
	cout << "tmp->MyBase::val=" << tmp->MyBase::getVal() << endl;
	cout << "tmp->derived_val=" << tmp->getVal() << endl;
	return tmp;
}
