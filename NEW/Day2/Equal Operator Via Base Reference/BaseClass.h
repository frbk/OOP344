#ifndef BASECLASS_H
#define BASECLASS_H

class BaseClass
{
	int base;
protected:
public:
    // We allow to copy derived objects pointed by BaseClass reference
	// This case is an exception to the Big-Three rule
	virtual BaseClass &operator =(const BaseClass &o) throw()
	{
		base = o.base;
		return *this;
	}

public:
	BaseClass(int v) throw() { base = v; }
	int getBaseValue() const throw() {return base; }
};

#endif