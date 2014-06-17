#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include "Node.h"

class SingleLinkedList
{
	Node *root;
public:
	SingleLinkedList();
	~SingleLinkedList();
	void AddNode(Node *);
	Node *getFirstNode();
	Node *getNextNode(Node *nd);
	int deleteNode(int val);
};

#endif