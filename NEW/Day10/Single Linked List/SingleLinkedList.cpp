#include "SingleLinkedList.h"

SingleLinkedList::SingleLinkedList()
{
	root = 0;
}


SingleLinkedList::~SingleLinkedList()
{
	Node *curr=root;
	Node *next;

	while(curr)
	{
		next = curr->next;
		delete curr;
		curr = next;
	}
}


void SingleLinkedList::AddNode(Node *nd)
{
	if (!root)
	{
		root = nd;
		return;
	}
	nd->next = root;
	root = nd;
}


Node *SingleLinkedList::getFirstNode()
{
	return root;
}


Node *SingleLinkedList::getNextNode(Node *nd)
{
	return nd->next;
}


int SingleLinkedList::deleteNode(int val)
{
	Node *prev=0;
	for (Node *nd=getFirstNode() ; nd ; nd=getNextNode(nd))
	{
		if (nd->getValue() == val)
		{
			if (!prev)  // we delete the first node
			{
				root = nd->next;
				delete nd;
				return 1;
			}
			else
			{
				prev->next = nd->next;
				delete nd;
				return 1;
			}
		}
		else
		{
			prev = nd;
		}
	}
	return 0;
}
