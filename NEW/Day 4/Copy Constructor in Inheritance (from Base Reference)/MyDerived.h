#ifndef MYDERIVED_H
#define MYDERIVED_H
#include "MyBase.h"

class MyDerived : public MyBase
{
	int deriv_val;
public:
	MyDerived(int val) : MyBase(val) { deriv_val = val +100; }
	virtual int getVal() const { return deriv_val; }
	virtual MyDerived *getCopy() const { return new MyDerived(*this); }
};

#endif
