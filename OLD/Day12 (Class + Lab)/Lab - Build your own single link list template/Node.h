#ifndef NODE_H
#define NODE_H

template <class L> class SingleLinkedList;  // forward declaration

template <class T>
class Node
{
	T   Value;
	Node *next;
   friend class SingleLinkedList<T>;
public:
	Node(T val)
	{
		Value = val;
		next = 0;
	}

	T getValue()
	{
		return Value;
	}
};

#endif