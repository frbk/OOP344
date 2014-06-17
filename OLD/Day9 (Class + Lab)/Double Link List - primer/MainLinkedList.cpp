#include <iostream>
#include "DoubleLinkedList.h"
#include "Node.h"

using namespace std;

void main()
{
	int n;
	Node  *node;
	Node *nd;
	Node *LastNode;
	DoubleLinkedList lList;
	char yn;

	do {
		cout << "Enter a number to insert in the Single Linked List:";
		cin >> n;

		node = new Node(n);
		lList.AddNode(node);
		cout << "Continue (Y/N)?:";
		cin >> yn;
	} while (yn=='Y' || yn=='y');

	for (nd=lList.getFirstNode() ; nd ; nd=lList.getNextNode(nd))
	{
		cout << nd->getValue() << ", ";
		LastNode = nd;
	}

	cout << "Delete node with value =";
	cin >> n;
	int del=lList.deleteNode(n);
	if (!del)
		cout << "Node not found" << endl;
	else
		cout << "Node was deleted" << endl;

	for (nd=lList.getLastNode() ; nd ; nd=lList.getPrevNode(nd))
	{
		cout << nd->getValue() << ", ";
	}
	cout << endl;
}