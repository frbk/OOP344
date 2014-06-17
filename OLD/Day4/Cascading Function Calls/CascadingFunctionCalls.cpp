#include <iostream>
using namespace std;

class Class2
{
public:
	Class2& function2a() {cout << "function2 a" << endl; return *this;}
	Class2& function2b() {cout << "function2 b" << endl; return *this;}
};

class Class1
{
	Class2 local;
public:
	Class2& function1() {cout << "function1" << endl; return local;}
};

void main()
{
	Class1 c1;
	c1.function1().function2a().function2b();
}