#include "Stack.h"

Stack::Stack()
{
	head = 0;
	size = 0;
}


Stack::~Stack()
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


void Stack::PushNode(Node *nd)
{
	if (!head)
	{
		head = nd;
	}
	else
	{
		nd->next = head;
		head = nd;
	}
	size++;
}


Node *Stack::PopNode()
{
	if (!head)
		return 0;
	Node *nd = head;
	head = nd->next;
	return nd;
}

void Stack::Push(int val)
{
	Node *nd = new Node(val);
	PushNode(nd);;
}


int Stack::Pop()
{
	Node *nd = PopNode();
	int obj = nd->getValue();
	delete nd;
	size--;
	return obj;
}


unsigned int Stack::getSize()
{
	return size;
}
