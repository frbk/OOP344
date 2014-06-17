#include <iostream>
using namespace std;

class MyClass
{
   int Val[5];

public:
  MyClass() { cout << "MyClass() Constructor" << endl; }
  ~MyClass() { cout << "~MyClass() Destructor" << endl; }

  void* operator new(size_t sz) {
    cout << "MyClass::new: " << sz << " bytes" << endl;
    return ::new char[sz];
  }

  void operator delete(void* p) {
    cout << "MyClass::delete" << endl;
    ::delete [] p;
  }

  void* operator new[](size_t sz) {
    cout << "MyClass::new[]: " << sz << " bytes" << endl;
    return ::new char[sz];
  }

  void operator delete[](void* p) {
    cout << "MyClass::delete[]" << endl;
    ::delete [] p;
  }
};

void main() {
  cout << "new MyClass" << endl;
  MyClass* obj = new MyClass;
  cout << endl << "delete MyClass" << endl;
  delete obj;
  cout << endl << "new MyClass[3]" << endl;
  /*
  The size displaied by the "NEW" operator should be 5*sizeof(int)*3 = 60 bytes.
  Instead we get 64 bytes.
  The extra 4 bytes represents are created by the memory manager. In this "int" value
  the memory manager holds the number of elements in the array. One of the reason is
  when the delete is invoked to know how many objects are created in order to call so many destructors.
  */
  MyClass* objArr = new MyClass[3];
  cout << "Hidden information: " << *(((int *)objArr)-1) << endl;
  cout << endl << "delete [] MyClass" << endl;
  delete [] objArr;
}