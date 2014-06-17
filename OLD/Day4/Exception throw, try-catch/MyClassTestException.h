#ifndef MY_CLASSTESTEXCEPTION_H
#define MY_CLASSTESTEXCEPTION_H
#include <iostream>
using namespace std;

class MyClassTestException
{
   int Val;
public:
   MyClassTestException(int i) { Val=i; cout << "Constructor TestException Val=" << Val << endl; }
   ~MyClassTestException() { cout << "Destructor TestException Val=" << Val << endl; }
};

#endif
