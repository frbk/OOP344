#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;

class Time
{
public:
   unsigned short Hour, Min, Sec;
   unsigned short Overflow;

public:
   Time();
   Time(unsigned short Hour, unsigned short Min, unsigned short Sec);
   void setTime(unsigned short Hour, unsigned short Min, unsigned short Sec, unsigned short Overflow=0);
   int operator < (Time &o);
   int operator > (Time &o);
   int operator == (Time &o);
   int operator != (Time &o);
   int operator <= (Time &o);
   int operator >= (Time &o);
   Time &operator ++();  // prefix operator e.g. ++t;
   Time &operator ++(int);  // postfix e.g. t++;
   Time &operator += (unsigned int val);   // Add seconds
   Time operator + (unsigned int val);   // Add seconds
   unsigned short getOverflow()  { return Overflow;}
   void resetOverflow()  { Overflow=0;}
   Time operator - (Time &t);

   friend ostream &operator <<(ostream &os, Time &t);
};

#endif
