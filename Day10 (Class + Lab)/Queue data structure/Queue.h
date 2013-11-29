#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

class Queue
{
	Node *head;
	Node *tail;
	unsigned int size;

public:
	Queue();
	~Queue();
	unsigned int getSize();
#ifdef NODE_HIDING
	void operator << (int);
	int operator >> (int &);
private:
#endif
	void EnqueueNode(Node *);
	Node *DequeueNode();
};

#endif