#ifndef NODE_H
#define NODE_H

#define NODE_HIDING

class Node
{
	int   Value;
	Node *next;
	friend class Queue;
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