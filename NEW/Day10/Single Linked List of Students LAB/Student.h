#ifndef STUDENT_H
#define STUDENT_H
#include <string>
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
   unsigned int getId() {return ID;}
   string getFN() {return FN;}
   string getLN() {return LN;}
};

#endif
