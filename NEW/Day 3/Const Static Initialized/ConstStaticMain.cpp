#include <iostream>
#include "ConstStatic.h"

using namespace std;


void main()
{
	cout << ConstStatic::i_ << endl;
	cout << ConstStatic::sh_ << endl;
	cout << ConstStatic::l_ << endl;
	cout << ConstStatic::ui_ << endl;
	cout << ConstStatic::ush_ << endl;
	cout << ConstStatic::ul_ << endl;
	cout << ConstStatic::f_ << endl;
	cout << ConstStatic::d_ << endl;
	cout << ConstStatic::c_ << endl;
	cout << static_cast<int>(ConstStatic::uc_) << endl;
	cout << ConstStatic::s_ << endl;

}
