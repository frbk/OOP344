#ifndef NODE_H
#define NODE_H

class Node
{
	int   Value;
	Node *next;
	friend class Stack;
public:
	Node(int val)
	{
		Value = val;
		next = 0;
	}

	int getValue()
	{
		return Value;
	}
};

#endif