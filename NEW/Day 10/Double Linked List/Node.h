#ifndef NODE_H
#define NODE_H

class Node
{
	int   Value;
	Node  *prev, *next;
	friend class DoubleLinkedList;
public:
	Node(int val)
	{
		Value = val;
		prev = 0;
		next = 0;
	}

	int getValue()
	{
		return Value;
	}
};

#endif