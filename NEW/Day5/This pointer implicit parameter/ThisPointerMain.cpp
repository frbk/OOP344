#include <iostream>
using namespace std;

class MyClass
{
public:
   MyClass *getThis() { return this; }
};

void main()
{
   MyClass a, b, c;
   cout << "Address of 'a'=" << &a << " and <this=" << a.getThis() << ">" << endl;
   cout << "Address of 'b'=" << &b << " and <this=" << b.getThis() << ">" << endl;
   cout << "Address of 'c'=" << &c << " and <this=" << c.getThis() << ">" << endl;
}
