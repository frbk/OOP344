#ifndef COURSE_H 
#define COURSE_H

#define LEN_COURSE_NAME  6

struct Course
{
   unsigned char Semester;
   char  Name[LEN_COURSE_NAME+1];
};

#endif