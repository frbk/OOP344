#include <iostream>

namespace Comp1
{
	class MyClass
	{
		int val;
	public:
		MyClass(int v) {val=v;}
		int getVal() {return val;}
	};
}

namespace Comp2
{
	class MyClass
	{
		int val;
	public:
		MyClass(int v) {val=v;}
		int getVal() {return val;}
	};
}

using namespace std;

void main()
{
	Comp1::MyClass a(1);
	Comp2::MyClass b(2);

	cout << "Comp1::MyClass=" << a.getVal() << endl;
	cout << "Comp1::MyClass=" << b.getVal() << endl;
	system("pause");
}