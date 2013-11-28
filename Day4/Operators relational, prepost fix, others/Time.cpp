#include "Time.h"

Time::Time()
{
   setTime(0, 0, 0);
}

Time::Time(unsigned short Hour, unsigned short Min, unsigned short Sec)
{
   setTime(Hour, Min, Sec);
}

void Time::setTime(unsigned short Hour, unsigned short Min, unsigned short Sec, unsigned short Overflow)
{
   this->Overflow = Overflow;
   this->Hour = Hour;
   this->Min = Min;
   this->Sec = Sec;
}

int Time::operator < (Time &o)
{
   if (Hour < o.Hour ||
      (Hour == o.Hour && Min < o.Min) ||
      (Hour == o.Hour && Min == o.Min && Sec < o.Sec) )
      return 1;
   else
      return 0;
}

int Time::operator > (Time &o)
{
   if (Hour > o.Hour ||
      (Hour == o.Hour && Min > o.Min) ||
      (Hour == o.Hour && Min == o.Min && Sec > o.Sec) )
      return 1;
   else
      return 0;
}

int Time::operator == (Time &o)
{
   if (Hour == o.Hour && Min == o.Min && Sec == o.Sec)
      return 1;
   else
      return 0;
}

int Time::operator != (Time &o)
{
      return !(*this == o);
}

int Time::operator <= (Time &o)
{
   if (*this < o || *this == o)
      return 1;
   else
      return 0;
}

int Time::operator >= (Time &o)
{
   if (*this > o || *this == o)
      return 1;
   else
      return 0;
}

Time &Time::operator ++()  // prefix operator e.g. ++t;
{
   Overflow = 0;
   Sec++;
   if(Sec==60)
   {
      Sec = 0;
      Min++;
      if (Min==60)
      {
         Hour++;
         if (Hour==24)
         {
            Hour=0;
            Overflow = 1;
         }
      }
   }
   return *this;
}

Time &Time::operator ++(int)  // postfix e.g. t++;
{
   ++(*this);
   return *this;
}

Time &Time::operator += (unsigned int val)   // Add seconds
{
   for (int i=0 ; i<val ; i++)
      ++(*this);
   return *this;
}

Time Time::operator + (unsigned int val)   // Add seconds
{
   Time temp(*this);
   temp += val;
   return temp;
}

Time Time::operator - (Time &t)
{
   short Hour, Min, Sec, Overflow;
   Overflow = 0;
   Sec = this->Sec;
   Sec = Sec - t.Sec;
   if (Sec <0)
   {
      Overflow = 1;
      Sec += 60;
   }
   Min = this->Min - t.Min - Overflow;;
   Overflow = 0;
   if(Min<0)
   {
      Overflow = 1;
      Min += 60;
   }
   Hour = this->Hour - t.Hour - Overflow;;
   Overflow = 0;
   if(Hour<0)
   {
      Overflow = 1;
      Hour += 60;
   }
   Time temp;
   temp.setTime(Hour, Min, Sec, Overflow);
   return temp;
}

ostream &operator <<(ostream &os, Time &t)
{
   os << t.Hour << ":" << t.Min << ":" << t.Sec;
   return os;
}
