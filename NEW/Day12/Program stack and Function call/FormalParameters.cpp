#include <iostream>
using namespace std;

void ParameterValue(int);
void ParameterAddress(int *);
void ParameterReference(int &);

void main()
{
	int n;

	n = 0;
	cout << "Before function ParameterValue n= " << n << endl;
	ParameterValue(n);
	cout << "After function ParameterValue n= " << n << endl << endl;

	n = 0;
	cout << "Before function ParameterAddress n= " << n << endl;
	ParameterAddress(&n);
	cout << "After function ParameterAddress n= " << n << endl << endl;

	n = 0;
	cout << "Before function ParameterReference n= " << n << endl;
	ParameterReference(n);
	cout << "After function ParameterReference n= " << n << endl << endl;
}


void ParameterValue(int val)
{
	val = 1;
	cout << "Parameter modified inside function ParameterValue val= " << val << endl;
}

void ParameterAddress(int *val)
{
	*val = 2;
	cout << "Parameter modified inside function ParameterAddress val= " << *val << endl;
}

void ParameterReference(int &val)
{
	val = 3;
	cout << "Parameter modified inside function ParameterReference val= " << val << endl;
}

