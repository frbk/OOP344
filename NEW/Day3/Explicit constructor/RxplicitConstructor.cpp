#include <iostream>
using namespace std;

class ParamClass
{
	double val;
public:
	/*explicit*/ ParamClass(double v)
	{
		val = v;
	}
	double getVal() {return val;}
};


class MyClass
{
	double val;
	char ch;
public:
	MyClass(ParamClass  o) { val = o.getVal(); }
	operator double(void) const {return val; }
};

void main()
{
	double val;
//*
	// BAD code with "explicit"
	MyClass a=1;    // with 'explicit'constructor ==> ERROR: Cannot convert 'int' to Param Class
	MyClass b=2.3;  // with 'explicit'constructor ==> ERROR: Cannot convert 'double' to ParamClass
	MyClass c='A';  // with 'explicit'constructor ==> ERROR: Cannot convert 'char' to ParamClass

	MyClass a2(1);
	MyClass b2(2.3);
	MyClass c2('c');
	MyClass d2(1.);
	val = b2;  // invokes the conversion opertor
	cout << "1) =" << val << endl;

	short sh=3;
    MyClass d(sh);
	val = d;  // invokes the conversion opertor
	cout << "2) =" << val << endl;
//*/

	// GOOD code with "explicit"
   MyClass e(ParamClass(9));
   val = e;  // invokes the conversion opertor
   cout << "3) =" << val << endl;

}
