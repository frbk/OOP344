/*
Fedor Barannik
SIN:028-127-108
*/
#ifndef STUDENTRECORDDATE_H
#define STUDENTRECORDDATE_H


#include "Course.h"


#define MAX_COURSES      18
#define LEN_FN           10
#define LEN_LN           10

class StudentRecordData
{
protected:
   double Marks[MAX_COURSES];
   unsigned int Age;
   unsigned int ID;
   unsigned int CourseCount;
   char FirstName[LEN_FN];
   char LastName[LEN_FN];
   Course  Courses[MAX_COURSES];
public:
	StudentRecordData(double marks[MAX_COURSES], unsigned int age, unsigned int id, unsigned int coursecount,char fn[LEN_FN], char ln[LEN_FN], Course c[MAX_COURSES]);
};

#endif
