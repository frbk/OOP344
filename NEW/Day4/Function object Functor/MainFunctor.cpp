#include <iostream>
using namespace std;

class MyClass
{
public:
	bool operator() (int val) { return val<0; }
	int funct() {return 9; }
};

void main()
{
	int i=5, ret;
	MyClass a;
	i=a.funct();    // call a function
	cout << "compare  3 < 0? " << a( i + 1 ) << endl;;    // call the function operator
	cout << "compare -3 < 0? " << a(-3) << endl;;
}
