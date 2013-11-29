#include "Queue.h"

Queue::Queue()
{
	head = tail = 0;
	size = 0;
}


Queue::~Queue()
{
	Node *nextNode;

	while(head)
	{
		nextNode = head->next;
		delete head;
		head = nextNode;
	}
}


#ifdef NODE_HIDING

void Queue::operator << (int val)
{
	Node *node = new Node(val);
	EnqueueNode(node);
}


int Queue::operator >> (int &val)
{
	Node *nd = DequeueNode();
	if (!nd)  return 0;
	val = nd->getValue();
	delete nd;
	return 1;
}

#endif

void Queue::EnqueueNode(Node *nd)
{
	if (!tail)
	{
		head = nd;
		tail = nd;
	}
	else
	{
		tail->next = nd;
		tail = nd;
	}
	size++;
}


Node *Queue::DequeueNode()
{
	if (!head)
		return 0;
	Node *nd;
	nd = head;
	head = head->next;
	size--;
	nd->next = 0;
	return nd;
}

unsigned int Queue::getSize()
{
	return size;
}