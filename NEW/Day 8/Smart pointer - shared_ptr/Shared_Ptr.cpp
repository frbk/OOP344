#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

class MyClass
{
	int val;
public:
	friend bool orderMyClass(shared_ptr<MyClass> &a, shared_ptr<MyClass> &b) {return a->getVal() < b->getVal();}
	static bool EqualTo(shared_ptr<MyClass> el) {return el->getVal()==2;}
	bool operator ()(shared_ptr<MyClass> el) {return el->getVal()==2;}
	MyClass(int v) {val=v;}
	~MyClass() {cout << "Destructor=" << val << endl;}
	int getVal() { return val;}
	string getType()
	{
		stringstream conv;
		conv << "MyClass=" << val;
		return conv.str();
	}
};

void main()
{
	int out = 0;
	{
		shared_ptr<MyClass>   sp1(new MyClass(1));
		cout << "dereferencing -> =" << sp1->getType() << endl;
		cout << "dereferencing * =" << (*sp1).getType() << endl;
		cout << ++out << " reference count sp1=" << sp1.use_count() << endl;
		cout << " getValue sp1=" << sp1->getVal() << endl;
		sp1.reset(new MyClass(11));
		cout << " getValue sp1=" << sp1->getVal() << endl;

		{
		shared_ptr<MyClass> sp2(sp1);
		cout << "1 reference count sp1=" << sp1.use_count() << " Unique=" << sp1.unique() << endl;
		cout << ++out << " reference count sp2=" << sp2.use_count() << " Unique=" << sp2.unique() << endl;
		}

		cout << ++out << " reference count sp1=" << sp1.use_count() << " Unique=" << sp1.unique() << endl;
		shared_ptr<MyClass> sp3;
		sp3 = sp1;
		cout << ++out << " reference count sp1=" << sp1.use_count() << " Unique=" << sp1.unique() << endl;
		sp3 = nullptr;
		cout << ++out << " reference count sp1=" << sp1.use_count() << " Unique=" << sp1.unique() << endl;

		cout << endl << "Swap sp1 & sp4" << endl;
		shared_ptr<MyClass>sp4(new MyClass(4));
		sp4.swap(sp1);
		cout << " getValue sp1=" << sp1->getVal() << endl;
		cout << " getValue sp4=" << sp4->getVal() << endl;
	}
	{
		cout << endl << "shaed_ptr in Vector" << endl;
		vector<shared_ptr<MyClass>> v;
		vector<shared_ptr<MyClass>>::iterator it;
		v.push_back(shared_ptr<MyClass>(new MyClass(3)));
		v.push_back(shared_ptr<MyClass>(new MyClass(5)));
		v.push_back(shared_ptr<MyClass>(new MyClass(2)));
		v.push_back(shared_ptr<MyClass>(new MyClass(1)));
		v.push_back(shared_ptr<MyClass>(new MyClass(4)));
		v.push_back(shared_ptr<MyClass>(new MyClass(2)));
		for (unsigned int i=0 ; i<v.size() ; i++)
			cout << "getVal=" << v[i]->getVal() << endl;
		sort(v.begin(), v.end(), orderMyClass);
		cout << endl << "After sorting:" << endl;
		for (unsigned int i=0 ; i<v.size() ; i++)
			cout << "getVal=" << v[i]->getVal() << endl;

		int iCount;
		iCount = count_if(v.begin(), v.end(), MyClass::EqualTo);
		cout << "MyClass::EqualTo (count_if)=" << iCount << endl;
		cout << "Find_if method" << endl;
		it = v.begin();
		while (it!=v.end())
		{
			it = find_if(it, v.end(), MyClass::EqualTo);
			if (it!=v.end())
			{
				cout << "find_if =" << it->get()->getVal() << endl;
				it++;
			}
			else
				cout << "value not found" << endl;
		}

		cout << "Replacing (replace_if) with 0(zero)" << endl;
/*
		shared_ptr<MyClass> zero(new MyClass(0));
		replace_if(v.begin(), v.end(), MyClass::EqualTo, zero);
		// or
*/
		replace_if(v.begin(), v.end(), MyClass::EqualTo, shared_ptr<MyClass>(new MyClass(0)));
		for (unsigned int i=0 ; i<v.size() ; i++)
			cout << "getVal=" << v[i]->getVal() << endl;
	}
}
