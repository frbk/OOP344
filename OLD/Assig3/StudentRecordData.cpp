
#include <string.h>
#include "StudentRecordData.h"


StudentRecordData::StudentRecordData(double marks[MAX_COURSES], unsigned int age, unsigned int id, unsigned int coursecount,char fn[LEN_FN], char ln[LEN_FN], Course c[MAX_COURSES]){
	for(int i=0;i < MAX_COURSES;i++){
		Marks[i] = marks[i];
	}
	Age = age;
	ID = id;
	CourseCount =coursecount;
	strcpy(FirstName,fn);
	strcpy(LastName,ln);
	for(int i=0;i < MAX_COURSES;i++){
		strcpy(Courses[i].Name,c[i].Name);
		Courses[i].Semester = c[i].Semester;
	}
}
