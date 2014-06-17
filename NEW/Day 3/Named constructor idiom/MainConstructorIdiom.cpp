#include <iostream>
#include "Temperature.h"

using namespace std;

void main()
{
	Temperature t1 = Temperature::Celsius(30);
	Temperature t2 = Temperature::Farenheit(80);

	cout << "t1=" << t1.getTemperatue() << endl;
	cout << "t2=" << t2.getTemperatue() << endl;
}