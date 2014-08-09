#include <iostream>

using namespace std;

class MyClass
{
	int i,j,k;
public:
	MyClass() :i(0), j(0), k(0)
	{}
	MyClass &setI(int v)
	{
		i=v;
		return *this;
	}
	MyClass &setJ(int v)
	{
		j=v;
		return *this;
	}
	MyClass &setK(int v)
	{
		k=v;
		return *this;
	}
	static MyClass Create() { return MyClass(); }
	int getI() { return i; }
	int getJ() { return j; }
	int getK() { return k; }
};

void main()
{
	MyClass a=MyClass::Create()
		      .setI(10)
			  .setJ(20)
			  .setK(30);
	cout << "i=" << a.getI() << endl;
	cout << "j=" << a.getJ() << endl;
	cout << "k=" << a.getK() << endl;
}
