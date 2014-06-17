#include <iostream>
using namespace std;

unsigned int FactorialLoop(unsigned int);
unsigned int FactorialRecursive(unsigned int);


void main()
{
	unsigned int n;
	unsigned int fact;

	do {
	cout << "Input a number greater or equal to zero:";
	cin >> n;
	} while (n<0);

	fact = FactorialLoop(n);
	cout << "Through loops " << n << "! =" << fact << endl;

	fact = FactorialRecursive(n);
	cout << "Through rexursion " << n << "! =" << fact << endl;
}

unsigned int FactorialLoop(unsigned int n)
{
	unsigned int res = 1;
	if (n==0)
		return res;
	for (int i=1 ; i<=n ; i++)
		res = res * i;
	return res;
}


 unsigned int FactorialRecursive(unsigned int n)
{
	if (n==0)
		return 1;
	else
		n = n * FactorialRecursive(n-1);
	return n;
}
