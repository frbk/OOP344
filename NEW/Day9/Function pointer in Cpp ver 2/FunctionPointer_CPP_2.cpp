#include <iostream>
using namespace std;

class Functions
{

	char   operation;
	float (Functions::*func)(float, float);

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

public:
   Functions(char op)
   {
      operation = op;
      switch(op)
      {
      case '+':
         func = &Functions::Plus;
         break;
      case '-':
         func = &Functions::Minus;
         break;
      case 'm':
         func = &Functions::Min;
         break;
      case 'M':
         func = &Functions::Max;
         break;
      default:
         func = 0;
         break;
      }
   }
   char getOperation() {return operation;}
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
	Functions funcArr[] = {Functions('+'), Functions('-'), Functions('m'), Functions('M'), Functions(0)};

	cout << "Enter the first number = ";
	cin >> a;
	cout << "Enter the second number = ";
	cin >> b;
	do {
		cout << "Chose an Operation Plus(+) or Minus(-) or Min(m) or Max(M): ";
		cin >> op;

		int found = 0;
		for (i=0 ; funcArr[i].getOperation() != 0 ; i++)
		{
			if (funcArr[i].getOperation() == op)
			{
				found = 1;
				break;
			}
		}
		if (found)
			funcArr[i].DisplayResult(a,b);
		else
			cout << "Operation not found" << endl;

		cout << "Continue (Y/N)?: ";
		cin >> cont;
	} while (cont=='y' || cont=='Y');
	return;
}
