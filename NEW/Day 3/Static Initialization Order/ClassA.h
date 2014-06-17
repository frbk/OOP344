#ifndef CLASSA_H
#define CLASSA_H
#include <iostream>

using namespace std;

class ClassA
{
public:
	ClassA() throw();
	void funcA() throw();
};

inline ClassA::ClassA() throw()
{
	cout << "ClassA::ctor" << endl;
}

#endif
