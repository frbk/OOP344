#include "Student.h"
int Student::getAge(){
	return Age;
}
char *Student::getFirstName() {
	return FirstName;
}
char *Student::getLastName() {
	return LastName;
}
int Student::getID(){
	return ID;
}
int Student::getCourseCount(){
	return CourseCount;
}
double *Student::getMarks(){
    return Marks;
}
Course *Student::getCourses(){
	return Courses;
}
double Student::getAverage(){
	double total = 0;
	for(int i = 0; i < getCourseCount();i++){
		total = total + getMarks()[i];
	}
	return total / getCourseCount();
}

