#include <iostream>
#include "VariableTemplate.h"
using namespace std;

void main()
{
	Variable<char>  ch('a');
	Variable<short> sh(1);
	Variable<long>  lg(2);
	Variable<float> fl(3);
	Variable<double> df(4);

	cout << "The Size of 'ch'=" << sizeof(ch) << " and inner size of val=" << ch.getSize() << " ,value= " << ch.getVal() << endl;
	cout << "The Size of 'sh'=" << sizeof(sh) << " and inner size of val="  << sh.getSize() << " ,value= " << sh.getVal() << endl;
	cout << "The Size of 'lg'=" << sizeof(lg) << " and inner size of val="  << lg.getSize() << " ,value= " << lg.getVal() << endl;
	cout << "The Size of 'fl'=" << sizeof(fl) << " and inner size of val="  << fl.getSize() << " ,value= " << fl.getVal() << endl;
	cout << "The Size of 'df'=" << sizeof(df) << " and inner size of val="  << df.getSize() << " ,value= " << df.getVal() << endl;

}