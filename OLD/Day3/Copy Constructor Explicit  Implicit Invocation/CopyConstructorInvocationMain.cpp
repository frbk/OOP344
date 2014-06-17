#include <iostream>
using namespace std;

/*
The Copy Constructor is invoked:

1.When an object is returned by value
2.When an object is passed (to a function) by value as an argument
3.When an object is thrown
4.When an object is caught
5.When an object is placed in a brace-enclosed initializer list
*/
class MyClass
{
   int val;
public:
   MyClass(int v) { val = v; }
   MyClass (MyClass &o)
   {
      val = o.val;
      cout << "Copy Constructor val=" << val << endl;
   }
   int getVal() { return val; }
};


MyClass Function(MyClass o)
{
   cout << "I just entered the Function" << endl;
   MyClass a(2);
   cout << "Prepare to exit the Function" << endl;
   return a;
}

void main()
{
   MyClass a(1);
   cout << "Prepare to call the Function" << endl;
   a = Function(a);
   cout << "a.val=" << a.getVal() << endl;

   cout << "Prepare to call the direct the Copy Constructor" << endl;
   MyClass b(a);
   try
   {
      cout << "Prepare to throw an Exception" << endl;
      throw MyClass(3);
   }
   catch(MyClass o)
   {
      cout << "I just caught the Exception" << endl;
      cout << "o.val=" << o.getVal() << endl;
   }
}
