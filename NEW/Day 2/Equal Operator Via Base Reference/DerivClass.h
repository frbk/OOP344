#ifndef DERIVCLASS_H
#define DERIVCLASS_H
#include "BaseClass.h"

class DerivClass : public BaseClass
{
	int der;
public:
	DerivClass(int v) throw()
		: BaseClass(v*10)
	{
		der = v;
	}

	DerivClass & operator = (const DerivClass &o) throw()
	{
		// the base class assignment operator must be invoked
		BaseClass::operator=(o);
		der = o.der;
		return *this;
	}

	// covariant return type
	virtual DerivClass &operator =(const BaseClass &o) throw()
	{
		BaseClass::operator=(o);
		const DerivClass *tmp = static_cast<const DerivClass *>(&o);
		der = tmp->der;
		return *this;
	}

	int getDerivValue() const throw() {return der; }
};

#endif