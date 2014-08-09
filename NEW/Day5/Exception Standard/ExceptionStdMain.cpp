#include <iostream>
#include <stdexcept>

using namespace std;

class MyException : public runtime_error
{
public:
	MyException(const char *str) : runtime_error(str) {}
};


class MyClass
{
public:
	void FuncRTE() throw (runtime_error)
	{
		throw runtime_error("Exception: runtime_error");
	}
	void FuncException() throw (runtime_error)
	{
		throw MyException("Exception: MyException");
	}
};


void main()
{
	try
	{
		MyClass a;
//		a.FuncException();
		a.FuncRTE();
	}
	// Exceptions in the list of catch block should be
	// listed from the most derived to the base class
	catch(MyException &e)
	{
		cout << e.what() << endl;
	}
	catch(runtime_error &e)
//	catch(exception &e)
    // class runtime_error is derived from class exception 
	{
		cout << e.what() << endl;
	}
	catch(...)
	{
		cout << "unknown error" << endl;
	}
}
