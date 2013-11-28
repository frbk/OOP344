#include <iostream>
using namespace std;

class Functions
{
public:
	char   operation;
	float (Functions::*func)(float, float);
	float function_func(float a, float b)
	{
		return ((*this).*func)(a,b);
	}

	float Plus(float a, float b)
	{
		return a+b;
	}

	float Minus(float a, float b)
	{
		return a-b;
	}

	float Min(float a, float b)
	{
		return a < b ? a : b;
	}

	float Max(float a, float b)
	{
		return a > b ? a : b;
	}

	void DisplayResult(float a, float b)
	{
		cout << "Result=" << ((*this).*func)(a,b) << endl;
	}
};

void main()
{
	int i;
	float a,b;
	char cont;
	char op;
	Functions fPlus;
	Functions funcArr[] = {{'+',&Functions::Plus}, {'-',&Functions::Minus}, {'m',&Functions::Min}, {'M',&Functions::Max}, {0,0}};

	cout << "Enter the first number = ";
	cin >> a;
	cout << "Enter the second number = ";
	cin >> b;
	do {
		cout << "Chose an Operation Plus(+) or Minus(-) or Min(m) or Max(M): ";
		cin >> op;

		int found = 0;
		for ( i=0 ; funcArr[i].operation!=0 ; i++)
		{
			if (funcArr[i].operation==op)
			{
				found = 1;
				break;
			}
		}
		if (found)
		{
			// For some reasons the statement "double ret=funcArr[i].func(a,b)" doesn't compile
			// Therefore for this reason we created the proxy function "function_func"
			double ret=funcArr[i].function_func(a,b);  
			funcArr[i].DisplayResult(a,b);
		}
		else
			cout << "Operation not found" << endl;

		cout << "Continue (Y/N)?: ";
		cin >> cont;
	} while (cont=='y' || cont=='Y');
	return;
}
