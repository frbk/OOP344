#include <iostream>
#include "DerivClass.h"
void MakeCopy(BaseClass &dest, const BaseClass &src);

using namespace std;

void main()
{
	DerivClass a(1);
	DerivClass b(2);
	DerivClass c(3);
	cout << "a.base=" << a.getBaseValue() << "  a.der=" << a.getDerivValue() << endl;
	cout << "b.base=" << b.getBaseValue() << "  b.der=" << b.getDerivValue() << endl;
	cout << "c.base=" << c.getBaseValue() << "  c.der=" << c.getDerivValue() << endl;

	b=a;
	cout << "b.base=" << b.getBaseValue() << "  b.der=" << b.getDerivValue() << endl;

	MakeCopy(c,a);
	cout << "c.base=" << c.getBaseValue() << "  c.der=" << c.getDerivValue() << endl;
}


void MakeCopy(BaseClass &dest, const BaseClass &src)
{
    // We try to copy derived objects pointed by BaseClass reference
	dest = src;
}