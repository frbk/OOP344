#ifndef CONSTSTATIC_H
#define CONSTSTATIC_H

#include <string>


/*
A "static const" data member is declared in the class and is normally defined in the source file .cpp
Integral types (e.g. char, short, int, long, and unsigned) can be initialized in the body of the class
*/


class ConstStatic
{
public:
	static const int i_ = 1;
	static const short sh_ = 2;
	static const long l_ = 3;
	static const unsigned int ui_ = 4;
	static const unsigned short ush_ = 5;
	static const unsigned long ul_ = 6;
	static const float f_;
	static const double d_;
	static const char c_ = 'c';
	static const unsigned char uc_ = 10;
    static const std::string s_;
};

#endif
