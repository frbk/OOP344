#include <iostream>
using namespace std;

class MyClass
{
   MyClass() {}
   static MyClass *inst;

 public:
   static MyClass *getInstance()
   {
      if ( MyClass::inst == 0 )
      {
         MyClass::inst = new MyClass();
      }
      return MyClass::inst;
   }


 private:
    int iVal;

 public:
    void setVal(int val) { iVal = val; }
    int getVal(void) { return iVal; }
};


MyClass *MyClass::inst=0;

void main()
{
   MyClass *cls1 = MyClass::getInstance();
   cout << "Value=" << cls1->getVal() << endl;

   cls1->setVal(4);
   cout << "Value (cls1)=" << cls1->getVal() << endl;
   MyClass *cls2 = MyClass::getInstance();
   cout << "Value (cls2)=" << cls2->getVal() << endl;

   MyClass::getInstance()->setVal(5);
   cout << "Value (cls1)=" << cls1->getVal() << endl;
   cout << "Value (cls2)=" << cls2->getVal() << endl;
}
