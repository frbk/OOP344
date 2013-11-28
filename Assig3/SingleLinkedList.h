/*
Fedor Barannik
SIN:028-127-108
*/
#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include "Student.h"

class SingleLinkedList
{
	Student *root;
public:
	SingleLinkedList();
	~SingleLinkedList();
	void AddNode(Student *node);
	Student *getFirstNode();
	Student *getNextNode(Student *node);
	/*
	int deleteNode(int val);
	*/
	void BubbleSort();
};

#endif