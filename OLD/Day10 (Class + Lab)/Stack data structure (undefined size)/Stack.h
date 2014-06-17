#ifndef STACK_H
#define STACK_H

#include "Node.h"

class Stack
{
	Node *head;
	unsigned int size;
	void PushNode(Node *);
	Node *PopNode();
public:
	Stack();
	~Stack();
	void Push(int);
	int Pop();
	unsigned int getSize();
};

#endif