#include "SingleLinkedList.h"
   /*
   keep the function body in the header file to allow to create
   the function body at the same time when the template <type> is resolved
   */

/*
template <class L>
SingleLinkedList<L>::SingleLinkedList()
{
	root = 0;
}

template <class L>
SingleLinkedList<L>::~SingleLinkedList()
{
	Node<L> *curr=root;
	Node<L> *next;

	while(curr)
	{
		next = curr->next;
		delete curr;
		curr = next;
	}
}

template <class L>
void SingleLinkedList<L>::AddNode(Node<L> *nd)
{
	if (!root)
	{
		root = nd;
		return;
	}
	nd->next = root;
	root = nd;
}

template <class L>
Node<L> *SingleLinkedList<L>::getFirstNode()
{
	return root;
}

template <class L>
Node<L> *SingleLinkedList<L>::getNextNode(Node<L> *nd)
{
	return nd->next;
}

template <class L>
int SingleLinkedList<L>::deleteNode(L val)
{
	Node<L> *prev=0;
	for (Node<L> *nd=getFirstNode() ; nd ; nd=getNextNode(nd))
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
*/