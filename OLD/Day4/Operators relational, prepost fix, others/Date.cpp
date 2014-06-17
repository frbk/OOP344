#include "Date.h"

const unsigned short Date::DaysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date()
{
   setDate(1900, 1, 1);
}

Date::Date(unsigned short Year, unsigned short Month, unsigned short Day)
{
   setDate(Year, Month, Day);
}

void Date::setDate(unsigned short Year, unsigned short Month, unsigned short Day)
{
   this->Year = Year;
   this->Month = Month;
   this->Day = Day;
}

int Date::operator < (Date &o)
{
   if (Year < o.Year ||
      (Year == o.Year && Month < o.Month) ||
      (Year == o.Year && Month == o.Month && Day < o.Day) )
      return 1;
   else
      return 0;
}

int Date::operator > (Date &o)
{
   if (Year > o.Year ||
      (Year == o.Year && Month > o.Month) ||
      (Year == o.Year && Month == o.Month && Day > o.Day) )
      return 1;
   else
      return 0;
}

int Date::operator == (Date &o)
{
   if (Year == o.Year && Month == o.Month && Day == o.Day)
      return 1;
   else
      return 0;
}

int Date::operator != (Date &o)
{
   return !(*this == o);
}

int Date::operator <= (Date &o)
{
   if (*this < o || *this == o)
      return 1;
   else
      return 0;
}

int Date::operator >= (Date &o)
{
   if (*this > o || *this == o)
      return 1;
   else
      return 0;
}

Date &Date::operator ++()     // prefix operator e.g. ++d;
{
   Day++;
   if (Day==DaysInMonth[Month-1])
   {
      Day=1;
      Month++;
      if (Month==13)
      {
         Month=1;
         Year++;
      }
   }
   return *this;
}

Date &Date::operator ++(int)     // postfix operator e.g. d++;
{
   ++(*this);
   return *this;
}

void Date::addDays(int days)
{
   Day += days;
   if (Day>DaysInMonth[Month-1])
   {
      Day = Day - DaysInMonth[Month-1];
      Month++;
      if(Month==13)
      {
         Month = 1;
      }
      addDays(0);
   }
}

Date Date::operator - (Date &d)
{
   short Year, Month, Day, Overflow, prevMonth;
   Overflow = 0;
   Day = this->Day - d.Day;
   if (Day < 0)
   {
      Overflow = 1;
      prevMonth = this->Month - 1;
      if (prevMonth==0)
         prevMonth = 11;
      Day += DaysInMonth[prevMonth];
   }
   Month = this->Month - d.Month - Overflow;
   Overflow = 0;
   if (Month<0)
   {
      Overflow = 1;
      Month += 12;
   }
   Year = this->Year - d.Year - Overflow;
   Date dt;
   dt.setDate(Year, Month, Day);
   return dt;
}

ostream &operator <<(ostream &os, Date &d)
{
   os << d.Year << "/" << d.Month << "/" << d.Day;
   return os;
}
