#include <iostream>

using namespace std;

class FuncOverload
{
	double val;
public:
	FuncOverload()
	{
		cout << "Constructor ";
		val = -1;
	}
	double setVal(int v)
	{
		cout << "setVal(int) ";
		val = v;
		return val;
	}
	double setVal(double v)
	{
		cout << "setVal(double) ";
		val = v;
		return val;
	}
	double setVal()
	{
		cout << "setVal() ";
		val = 0;
		return val;
	}
	double getVal() const
	{
		return val;
	}
};


void main()
{
	FuncOverload  a;
	cout << "val=" << a.getVal() << endl;
	a.setVal(1);
	cout << "val=" << a.getVal() << endl;
	a.setVal(2.);
	cout << "val=" << a.getVal() << endl;
	a.setVal();
	cout << "val=" << a.getVal() << endl;
}
