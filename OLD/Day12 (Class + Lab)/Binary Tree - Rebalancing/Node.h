#ifndef NODE_H
#define NODE_H

class Node
{
	int   Value;
	Node *left;
	Node *right;
	friend class BinaryTree;
public:
	Node(int val)
	{
		Value = val;
		left = right = 0;
	}

	int getValue()
	{
		return Value;
	}
};

#endif