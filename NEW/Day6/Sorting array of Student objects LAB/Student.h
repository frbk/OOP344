#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Student
{
   string FN, LN;
   unsigned int ID;
public:
   Student() {}
   Student(char *fn, char *ln, unsigned int Id)
   {
      FN = fn;
      LN = ln;
      ID = Id;
   }

   bool operator > (Student &st)
   {
      if (LN > st.LN ||
         (LN == st.LN && FN > st.FN) )
         return true;
      else
         return false;
   }

   friend ostream &operator << (ostream &os, Student &st)
   {
      		os << setw(35) << st.FN << setw(35) << st.LN << setw(10) << st.ID << endl;;
            return os;
   }
   unsigned int getId() {return ID;}
   string getFN() {return FN;}
   string getLN() {return LN;}
};

#endif
