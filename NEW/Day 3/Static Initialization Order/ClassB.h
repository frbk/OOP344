#ifndef CLASSB_H
#define CLASSB_H
#include <iostream>
#include "ClassA.h"

using namespace std;

class ClassB
{
	static ClassA  obj;
public:
	ClassB() throw();
};

inline ClassB::ClassB() throw()
{
	cout << "ClassB::ctor" << endl;
	obj.funcA();
}

#endif
