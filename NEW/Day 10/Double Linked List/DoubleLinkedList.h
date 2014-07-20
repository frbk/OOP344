#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "Node.h"

class DoubleLinkedList
{
	Node *head;
	Node *tail;
public:
	DoubleLinkedList();
	~DoubleLinkedList();
	void AddNode(Node *);
	Node *getFirstNode();
	Node *getLastNode();
	Node *getNextNode(Node *nd);
	Node *getPrevNode(Node *nd);
	int deleteNode(int val);
};

#endif