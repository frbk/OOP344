#ifndef BASECLASS_H
#define BASECLASS_H

class BaseClass
{
	int base;
protected:
    // We desallow to copy derived objects pointed by BaseClass reference
	// This case is an exception to the Big-Three rule
	void operator =(const BaseClass &o) throw()
	{
		base = o.base;
		return;
	}

public:
	BaseClass(int v) throw() { base = v; }
	int getBaseValue() const throw() {return base; }
};

#endif