#include <iostream>

using namespace std;

class ThrowClass
{
public:
	ThrowClass(int ) { throw 1; }
};


class MyClass
{
	ThrowClass a;
public:
	MyClass()
		try	: a(1)
	{
	}
	catch(int e)
	{
		cout << "Initializer List catch" << e << endl;
	}
};


void main()
{
	try
	{
		MyClass a;
	}
	catch(int e)
	{
		cout << "Main catch" << endl;
	}
}
