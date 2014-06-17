#include <iostream>
#include "Queue.h"

using namespace std;
/*
Queue : FIFO := First-In-First_Out
The Queue aplication uses a modified Sigle Link List that besides the HEAD it has also a TAIL.
The Enqueue is done through the TAIL
The Dequeue is done from the HEAD

In Node.h use "#define NODE_HIDING" to avoid the management of the Node in the client (main) function
In Node.h use "#undef NODE_HIDING" to handle the management of the Node in the client (main) function
*/
#ifdef NODE_HIDING

void main()
{
	int n;
	Queue queue;
	char yn;

	do {
		cout << "Enter a number to insert in the Queue: ";
		cin >> n;

		queue << n;   // Enqueue
		cout << "Continue (Y/N)?:";
		cin >> yn;
	} while (yn=='Y' || yn=='y');

	cout << "Queue has " << queue.getSize() << " objects" << endl;
	while (queue >> n)    // Dequeue
	{
		cout << n << ", ";
	}
}

#else

void main()
{
	int n;
	Node  *node;
	Node *nd;
	Queue queue;
	char yn;

	do {
		cout << "Enter a number to insert in the Queue: ";
		cin >> n;

		node = new Node(n);
		queue.EnqueueNode(node);
		cout << "Continue (Y/N)?:";
		cin >> yn;
	} while (yn=='Y' || yn=='y');

	cout << "Queue has " << queue.getSize() << " objects" << endl;
	while ((nd=queue.DequeueNode()))
	{
		cout << nd->getValue() << ", ";
		delete nd;
	}
}

#endif
