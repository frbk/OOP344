#include "Timestamp.h"


Timestamp::Timestamp()
 {}

Timestamp::Timestamp(unsigned short Year
                   , unsigned short Month
                   , unsigned short Day
                   , unsigned short Hour
                   , unsigned short Min
                   , unsigned short Sec)
{
   date.setDate(Year, Month, Day);
   time.setTime(Hour, Min, Sec);
}

int Timestamp::operator < (Timestamp &o)
{
   if (date < o.date ||
      date == o.date && time < o.time)
      return 1;
   else
      return 0;
}

int Timestamp::operator > (Timestamp &o)
{
   if (date > o.date ||
      date == o.date && time > o.time)
      return 1;
   else
      return 0;
}

int Timestamp::operator == (Timestamp &o)
{
   if (date == o.date && time == o.time)
      return 1;
   else
      return 0;
}

int Timestamp::operator != (Timestamp &o)
{
   return !(*this == o);
}

int Timestamp::operator <= (Timestamp &o)
{
   if (*this < o || *this == o)
      return 1;
   else
      return 0;
}

int Timestamp::operator >= (Timestamp &o)
{
   if (*this > o || *this == o)
      return 1;
   else
      return 0;
}

Timestamp &Timestamp::operator ++()  // prefix operator e.g. ++t;
{
   ++time;
   if (time.getOverflow())
   {
      time.resetOverflow();
      ++date;
   }
   return *this;
}

Timestamp &Timestamp::operator ++(int)  // postfix operator e.g. t++;
{
   ++time;
   if (time.getOverflow())
   {
      time.resetOverflow();
      ++date;
   }
   return *this;
}

Timestamp &Timestamp::operator += (unsigned int val)   // Add seconds
{
   time += val;
   return *this;
}

void Timestamp::addDays(int days)
{
   date.addDays(days);
}


Timestamp Timestamp::operator + (unsigned int val)   // Add seconds
{
   Timestamp temp(*this);
   temp += val;
   return temp;
}

Timestamp Timestamp::operator - (Timestamp &ts)
{
   Timestamp temp1, temp2;
   if (*this > ts)
   {
      temp1 = *this;
      temp2 = ts;
   }
   else
   {
      temp1 = ts;
      temp2 = *this;
   }
   Time t = temp1.time - temp2.time;
   unsigned short daysAdjustment = t.getOverflow();
   temp2.addDays(daysAdjustment);
   Date dt = temp1.date - temp2.date;
   Timestamp temp(dt.Year, dt.Month, dt.Day, t.Hour, t.Min, t.Sec);
   return temp;
}

ostream &operator <<(ostream &os, Timestamp &ts)
{
   os << ts.date << " " << ts.time;
   return os;
}
