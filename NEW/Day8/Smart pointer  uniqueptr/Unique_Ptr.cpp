#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

class BaseClass
{
public:
	virtual string getVal()=0;
	virtual int getValNumber()=0;
};

class MyClass : public BaseClass
{
	int val;
	string name;
public:
	MyClass(int v) : name("MyClass") {val = v;}
	~MyClass() {cout << "Destructor=" << val << endl;}
	static bool EqualTo(unique_ptr<MyClass> el) {return el->getValNumber()==2;}
	int getValNumber()
	{
		return val;
	}
	void setValue(int v) { val=v; }
	string getVal()
	{
		ostringstream convert;
		convert << name << "=" << val;
		return convert.str();
	}
};

class YourClass : public BaseClass
{
	int val;
	string name;
public:
	YourClass(int v) : name("YourClass") {val = v;}
	~YourClass() {cout << "Destructor=" << val << endl;}
	int getValNumber()
	{
		return val;
	}
	string getVal()
	{
		ostringstream convert;
		convert << name << "=" << val;
		return convert.str();
	}
};

unique_ptr<MyClass> Factory(int val)
{
	return unique_ptr<MyClass>(new MyClass(val));
}

bool orderMyClass(unique_ptr<MyClass> &a, unique_ptr<MyClass> &b) {return a->getValNumber() < b->getValNumber();}
bool orderBaseClass(unique_ptr<BaseClass> &a, unique_ptr<BaseClass> &b) {return a->getValNumber() < b->getValNumber();}

void main()
{

	{
		cout << endl << "unique_ptr for one Object" << endl;
		unique_ptr<MyClass> ap1(new MyClass(101));
		cout << "ap->getVal=" << ap1->getVal() << endl;
		unique_ptr<MyClass> ap2;
		ap2 = unique_ptr<MyClass>(new MyClass(102));
		cout << "ap2->getVal=" << ap2->getVal() << endl;
		MyClass *p = ap2.get();
		p->setValue(122);
		cout << "p->getVal=" << p->getVal() << endl;
		cout << "ap2->getVal=" << ap2->getVal() << endl;
		ap2.reset(new MyClass(132));
		cout << "after Reset ap2->getVal=" << ap2->getVal() << endl;
		p = ap2.release();
		p->setValue(132);
		cout << "p->getVal=" << p->getVal() << endl;
		if (ap2)
			cout << "ap2->getVal=" << ap2->getVal() << endl;
		else
			cout << "ap2 was deleted" << endl;
	}
	{
		cout << endl << "unique_ptr in Vector" << endl;
		vector<unique_ptr<MyClass>> v;
		v.push_back(unique_ptr<MyClass>(new MyClass(3)));
		v.push_back(unique_ptr<MyClass>(new MyClass(5)));
		v.push_back(unique_ptr<MyClass>(new MyClass(2)));
		v.push_back(unique_ptr<MyClass>(new MyClass(1)));
		v.push_back(unique_ptr<MyClass>(new MyClass(4)));
		v.push_back(unique_ptr<MyClass>(new MyClass(2)));
		for (unsigned int i=0 ; i<v.size() ; i++)
			cout << "getVal=" << v[i]->getVal() << endl;
		sort(v.begin(), v.end(), orderMyClass);
		cout << endl << "After sorting:" << endl;
		for (unsigned int i=0 ; i<v.size() ; i++)
			cout << "getVal=" << v[i]->getVal() << endl;
	}
	{
		cout << endl << "unique_ptr returned from Factory" << endl;
		unique_ptr<MyClass> o = Factory(7);
		cout << "returned from Factory=" << o->getVal() << endl;
	}
	{
		cout << endl << "unique_ptr in Vector with Polymorphism" << endl;
		vector<unique_ptr<BaseClass>> v;
		v.push_back(unique_ptr<BaseClass>(new YourClass(3)));
		v.push_back(unique_ptr<BaseClass>(new MyClass(6)));
		v.push_back(unique_ptr<BaseClass>(new YourClass(5)));
		v.push_back(unique_ptr<BaseClass>(new YourClass(1)));
		v.push_back(unique_ptr<BaseClass>(new MyClass(4)));
		v.push_back(unique_ptr<BaseClass>(new MyClass(2)));
		for (unsigned int i=0 ; i<v.size() ; i++)
			cout << "getVal=" << v[i]->getVal() << endl;
		sort(v.begin(), v.end(), orderBaseClass);
/* ERROR when used with unique_ptr
//		replace_if(v.begin(), v.end(), MyClass::EqualTo, unique_ptr<MyClass>(new MyClass(0)));
*/
		cout << endl << "After sorting:" << endl;
		for (unsigned int i=0 ; i<v.size() ; i++)
			cout << "getVal=" << v[i]->getVal() << endl;
	}
}