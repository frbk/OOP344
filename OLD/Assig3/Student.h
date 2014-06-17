//node
#ifndef STUDENT_H 
#define STUDENT_H

#include "StudentRecordData.h"


class Student: public StudentRecordData{
	Student *next;
	friend class SingleLinkedList;
public:
	Student(double marks[MAX_COURSES], unsigned int age, unsigned int id, unsigned int coursecount,char fn[LEN_FN], char ln[LEN_FN], Course c[MAX_COURSES]):StudentRecordData(marks,age,id,coursecount,fn, ln, c){
		next = 0;
	}
	int getAge();
	char *getFirstName();
	char *getLastName();
	int getID();
	double getAverage();
	int getCourseCount();
	double *getMarks();
	Course *getCourses();
};
#endif

/*
unsigned int Age;
	unsigned int ID;
	unsigned int CourseCount;
	char FirstName[LEN_FN];
	char LastName[LEN_FN];
	Course  Courses[MAX_COURSES];
*/