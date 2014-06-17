#include <iostream>
using namespace std;

/*
Fibonacci numbers:
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, etc.
a[n] = a[n-1] + a[n-2]
*/
unsigned int FibonacciLoop(unsigned int);
unsigned int FibonacciRecursive(unsigned int);

void main()
{
	unsigned int n;
	unsigned int fib;
	do {
	cout << "Input a number greater or equal to zero:";
	cin >> n;
	} while (n<0);

	fib = FibonacciLoop(n);
	cout << "Through loops " << "Fibonacci(" << n<< ") =" << fib << endl;

	fib = FibonacciRecursive(n);
	cout << "Through recursion " << "Fibonacci(" << n<< ") =" << fib << endl;
}


unsigned int FibonacciLoop(unsigned int index)
{
	unsigned int a1 = 0;
	unsigned int a2 = 1;
	unsigned int fib = a2;
	if (index==0)
		return 0;
	if (index==1)
		return 1;
	for (int i=2 ; i<=index ; i++)
	{
		fib = a1 + a2;
		a1 = a2;
		a2 = fib;
	}
	return fib;
}


unsigned int FibonacciRecursive(unsigned int n)
{
	if (n==0)
		return 0;
	if (n==1)
		return 1;
	return FibonacciRecursive(n-1) + FibonacciRecursive(n-2);
}
