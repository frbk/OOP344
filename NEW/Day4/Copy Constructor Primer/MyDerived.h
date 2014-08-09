#ifndef MYDERIVED_H
#define MYDERIVED_H
#include "MyBase.h"

class MyDerived : public MyBase
{
	int deriv_val;
public:
	MyDerived(int val) : MyBase(val) { deriv_val = val +100; }
	virtual int getVal() { return deriv_val; }
};

#endif
