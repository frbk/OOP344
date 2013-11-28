#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date
{
public:
   unsigned short Year, Month, Day;
   static const unsigned short DaysInMonth[12];
public:
   Date();
   Date(unsigned short Year, unsigned short Month, unsigned short Day);
   void setDate(unsigned short Year, unsigned short Month, unsigned short Day);
   int operator < (Date &o);
   int operator > (Date &o);
   int operator == (Date &o);
   int operator != (Date &o);
   int operator <= (Date &o);
   int operator >= (Date &o);
   Date &operator ++();     // prefix operator e.g. ++d;
   Date &operator ++(int);     // postfix operator e.g. d++;
   Date operator - (Date &d);
   void addDays(int days);

   friend ostream &operator <<(ostream &os, Date &d);

};

#endif