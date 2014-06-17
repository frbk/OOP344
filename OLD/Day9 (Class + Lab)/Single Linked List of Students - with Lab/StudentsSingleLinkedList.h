#ifndef StudentsSingleLinkedList_H
#define StudentsSingleLinkedList_H

#include "StudentNode.h"

class StudentsSingleLinkedList
{
	StudentNode *root;
public:
	StudentsSingleLinkedList();
	~StudentsSingleLinkedList();
	void AddNode(StudentNode *);
	StudentNode *getFirstNode();
	StudentNode *getNextNode(StudentNode *nd);
	int deleteNodeByID(int val);
};

#endif