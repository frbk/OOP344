#include <iostream>
using namespace std;

class MyBase
{
public:
	MyBase()
	{
		cout << "Constructor MyBase" << endl;
//		throw 1;   // exception thrown in constructor skips execution of destructor
	}
	~MyBase()
	{
		cout << "~MyBase" << endl;
	}
};

class MyClass : public MyBase
{
	int Val;
public:
	MyClass()
		: MyBase()
	{
		cout << "Constructor MyClass" << endl;
//		throw 2;   // exception thrown in constructor skips execution of destructor
	}
	MyClass(int v)
	{
		Val = v;
	}
	~MyClass()
	{
		cout << "~MyClass" << endl;
//		throw 3;    // exception thrown in destructor leaves program unstable and therefore the program will ABORT
	}
};


void main()
{
	try
	{
		MyClass a;
		MyClass b=2;
		MyClass c(2);
	}
	catch(int e)
	{
		cout << "Catch=" << e << endl;
	}
}