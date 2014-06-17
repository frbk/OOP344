#include <iostream>
#include <ciso646>
using namespace std;

void main()
{
	bool a = true;
	bool b = false;
	int c = 2;
	int d = 3;

	// sticky setting forcing bool values to be displaied in literals "true" or "false"
	cout << boolalpha;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
	cout << "d=" << d << endl;

	cout << "a && a= " << (a and a) << endl;
	cout << "a && b= " << (a and b) << endl;
	cout << "a || a= " << (a or a) << endl;
	cout << "a || b= " << (a or b) << endl;
	cout << "!a= " << (not a) << endl;
	cout << "!b= " << (not b) << endl;
	cout << "a != b= " << (a not_eq b) << endl;
	cout << "c & d= " << (c bitand d) << endl;
	cout << "c | d= " << (c bitor d) << endl;
	cout << "c ^ d= " << (c xor d) << endl;
	cout << "~c " << (compl c) << endl;
	cout << "c &= d " << (c and_eq d) << "  c=" << c<< endl;
	cout << "c |= d " << (c or_eq d) << "  c=" << c << endl;
	cout << "c ^= d  " << (c xor_eq d) << "  c=" << c << endl;
}
