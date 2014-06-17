#include <iostream>
using namespace std;

class DCBaseClass
{
protected:
   char *sz;
 public:
    DCBaseClass() {sz=0; }

    DCBaseClass(char *text)
    {
       sz = new char[strlen(text)+1];
       strcpy(sz,text);
    }
    char * const getText() {return sz; }
    int getTextAddress() {return reinterpret_cast<int>(sz); }
    virtual ~DCBaseClass()
    {
       cout << "Deleting ... " << getTextAddress() << endl;
       delete sz;
    }
};

class DeepCopy : public DCBaseClass
{
public:
   DeepCopy() : DCBaseClass() {}
   DeepCopy(char *text) : DCBaseClass(text) {}

   DeepCopy(DeepCopy &o)
   {
       sz = new char[strlen(o.sz)+1];
       strcpy(sz,o.sz);
   }

   DeepCopy & operator =(DeepCopy &o)
   {
       delete sz;
       sz = new char[strlen(o.sz)+1];
       strcpy(sz,o.sz);
       return *this;
   }
};

class ShallowCopy : public DCBaseClass
{
public:
   ShallowCopy() : DCBaseClass() {}
   ShallowCopy(char *text) : DCBaseClass(text) {}
};

/*
  Uncommenting the ShallowCopy objects we will encounter an execution failure
  at the end of the of the scope where these objects were created. The failure
  is due to the fact that the ShallowCopy objects use a common heap memory region.
*/
void main()
{
   ShallowCopy  objShallow("Heap text");
//   ShallowCopy  sc(objShallow);
   cout << "objShallow Text=" << objShallow.getText() << endl;
   cout << "objShallow address=" << objShallow.getTextAddress() << endl;
//   cout << "sc Text=" << sc.getText() << endl;
//   cout << "sc address=" << sc.getTextAddress() << endl;
   cout << endl;

   DeepCopy  objDeep("Heap text");
   DeepCopy  dc(objDeep);
   cout << "ObjDeep Text=" << objDeep.getText() << endl;
   cout << "ObjDeep address=" << objDeep.getTextAddress() << endl;
   cout << "dc Text=" << dc.getText() << endl;
   cout << "dc address=" << dc.getTextAddress() << endl;
   cout << endl;
/*
   ShallowCopy  scEqual;
   scEqual = objShallow;
   cout << "objShallow Text=" << objShallow.getText() << endl;
//   cout << "objShallow address=" << sc.getTextAddress() << endl;
   cout << "scEqual Text=" << scEqual.getText() << endl;
   cout << "scEqual address=" << scEqual.getTextAddress() << endl;
   cout << endl;
*/
   DeepCopy  dcEqual;
   dcEqual = objDeep;
   cout << "ObjDeep Text=" << objDeep.getText() << endl;
   cout << "ObjDeep address=" << objDeep.getTextAddress() << endl;
   cout << "dcEqual Text=" << dcEqual.getText() << endl;
   cout << "dcEqual address=" << dcEqual.getTextAddress() << endl;
   cout << endl;
}
