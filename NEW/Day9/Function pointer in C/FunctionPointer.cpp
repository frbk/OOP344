#include <iostream>
using namespace std;

float Plus(float a, float b);
float Minus(float a, float b);
float Min(float a, float b);
float Max(float a, float b);

class Functions
{
public:
	char   operation;
	float (*func)(float, float);
};

void main()
{
	int i;
	float a,b;
	char cont;
	char op;
	Functions funcArr[] = {{'+',Plus}, {'-',Minus}, {'m',Min}, {'M',Max}, {0,0}};

	cout << "Enter the first number =";
	cin >> a;
	cout << "Enter the second number =";
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
			cout << "Result=" << funcArr[i].func(a,b) << endl;
		else
			cout << "Operation not found" << endl;

		cout << "Continue (Y/N)?: ";
		cin >> cont;
	} while (cont=='y' || cont=='Y');
	return;
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