#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include <iostream>
#include "Date.h"
#include "Time.h"
using namespace std;


class Timestamp
{
public:
   Date date;
   Time time;
public:
   Timestamp();
   Timestamp(unsigned short Year
           , unsigned short Month
           , unsigned short Day
           , unsigned short Hour
           , unsigned short Min
           , unsigned short Sec);
   int operator < (Timestamp &o);
   int operator > (Timestamp &o);
   int operator == (Timestamp &o);
   int operator != (Timestamp &o);
   int operator <= (Timestamp &o);
   int operator >= (Timestamp &o);
   Timestamp &operator ++();  // prefix operator e.g. ++t;
   Timestamp &operator ++(int);  // postfix operator e.g. t++;
   Timestamp &operator += (unsigned int val);   // Add seconds
   Timestamp operator + (unsigned int val);   // Add seconds
   Timestamp operator - (Timestamp &ts);
   void addDays(int days);

   friend ostream &operator <<(ostream &os, Timestamp &ts);
};

#endif
