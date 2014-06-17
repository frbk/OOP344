#include <iostream>
#include "SingleLinkedList.h"
#include "Node.h"

using namespace std;

void main()
{
   // Int
	int n;
	Node<int>  *node;
	Node<int> *nd;
	SingleLinkedList<int> lList;
	char yn;

	do {
		cout << "Enter a number to insert in the Single Linked List: ";
		cin >> n;

		node = new Node<int>(n);
		lList.AddNode(node);
		cout << "Continue (Y/N)?:";
		cin >> yn;
	} while (yn=='Y' || yn=='y');

	for (nd=lList.getFirstNode() ; nd ; nd=lList.getNextNode(nd))
	{
		cout << nd->getValue() << ", ";
	}

	cout << "Delete node with value = ";
	cin >> n;
	int del=lList.deleteNode(n);
	if (!del)
		cout << "Node not found" << endl;
	else
		cout << "Node was deleted" << endl;

	for (nd=lList.getFirstNode() ; nd ; nd=lList.getNextNode(nd))
	{
		cout << nd->getValue() << ", ";
	}
	cout << endl;

   // Double
	double d;
	Node<double>  *nodeD;
	Node<double> *ndD;
	SingleLinkedList<double> lListD;

	do {
		cout << "Enter a number to insert in the Single Linked List: ";
		cin >> d;

		nodeD = new Node<double>(d);
		lListD.AddNode(nodeD);
		cout << "Continue (Y/N)?:";
		cin >> yn;
	} while (yn=='Y' || yn=='y');

	for (ndD=lListD.getFirstNode() ; ndD ; ndD=lListD.getNextNode(ndD))
	{
		cout << ndD->getValue() << ", ";
	}
}