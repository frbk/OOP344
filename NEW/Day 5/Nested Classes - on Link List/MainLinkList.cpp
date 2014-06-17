#include <iostream>
#include "LinkList.h"

void main()
{
	LinkList a;
	a.Add(1);
	a.Add(2);
	a.Add(3);
	a.Add(4);
	a.Add(5);
	a.Add(6);
	a.Add(7);

	LinkList b;
	b=a;
	b.Add(8);
	b.Add(9);

	LinkList c(b);

	cout << "List A" << endl;
	cout << a;
	cout << "List B" << endl;
	cout << b;
	cout << "List C" << endl;
	cout << c;
}
