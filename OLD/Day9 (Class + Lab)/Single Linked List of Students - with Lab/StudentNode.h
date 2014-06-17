#ifndef STUDENTNODE_H
#define STUDENTNODE_H
#include "Student.h"

class StudentNode
{
	Student   Value;
	StudentNode *next;
	friend class StudentsSingleLinkedList;
public:
	StudentNode(Student &val)
	{
		Value = val;
		next = 0;
	}

	Student &getValue()
	{
		return Value;
	}
};

#endif