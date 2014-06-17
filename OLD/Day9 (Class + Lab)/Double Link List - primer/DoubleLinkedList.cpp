#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList()
{
	head = 0;
	tail = 0;
}


DoubleLinkedList::~DoubleLinkedList()
{
	Node *curr=head;
	Node *next;

	while(curr)
	{
		next = curr->next;
		delete curr;
		curr = next;
	}
}


void DoubleLinkedList::AddNode(Node *nd)
{
	if (!head)
	{
		head = nd;
		tail = nd;
		return;
	}
	head->prev = nd;
	nd->next = head;
	head = nd;
}


Node *DoubleLinkedList::getFirstNode()
{
	return head;
}

Node *DoubleLinkedList::getLastNode()
{
	return tail;
}

Node *DoubleLinkedList::getNextNode(Node *nd)
{
	return nd->next;
}

Node *DoubleLinkedList::getPrevNode(Node *nd)
{
	return nd->prev;
}

int DoubleLinkedList::deleteNode(int val)
{
	for (Node *nd=getFirstNode() ; nd ; nd=getNextNode(nd))
	{
		if (nd->getValue() == val)
		{
			if (!nd->prev)  // we delete the first node
			{
				head = nd->next;
				if(nd->next)
					nd->next->prev=0;
				else
					tail = 0;
				delete nd;
				return 1;
			}
			else
			{
				nd->prev->next = nd->next;
				if (nd->next)
					nd->next->prev = nd->prev;
				else
					tail = nd->prev;
				delete nd;
				return 1;
			}
		}
	}
	return 0;
}
