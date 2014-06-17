#include "StudentsSingleLinkedList.h"

StudentsSingleLinkedList::StudentsSingleLinkedList()
{
	root = 0;
}


StudentsSingleLinkedList::~StudentsSingleLinkedList()
{
	StudentNode *curr=root;
	StudentNode *next;

	while(curr)
	{
		next = curr->next;
		delete curr;
		curr = next;
	}
}


void StudentsSingleLinkedList::AddNode(StudentNode *nd)
{
	if (!root)
	{
		root = nd;
		return;
	}
	nd->next = root;
	root = nd;
}


StudentNode *StudentsSingleLinkedList::getFirstNode()
{
	return root;
}


StudentNode *StudentsSingleLinkedList::getNextNode(StudentNode *nd)
{
	return nd->next;
}


int StudentsSingleLinkedList::deleteNodeByID(int val)
{
	StudentNode *prev=0;
	for (StudentNode *nd=getFirstNode() ; nd ; nd=getNextNode(nd))
	{
		if (nd->getValue().getId() == val)
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
