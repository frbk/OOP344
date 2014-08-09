#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Node.h"

class BinaryTree
{
   Node *aNd, *prevNd;   // Used in DeleteNode
   bool  isDisplay;
	Node *head;
	unsigned int size;
	void InsertNode(Node *tree, Node *nd);
	void ClearTree(Node *nd);
	void PreOrder(Node *nd);		// Root, Left, Right
	void InOrder(Node *nd);		// Lest, Root, Right
	void PostOrder(Node *nd);		// Lest, Right, Root
	void LevelOrder(Node *nd);	// Level by level - queue based)
   int SearchForNode(int val, Node *nd, Node *prevNd);
	void DisplayNode(Node *nd);

public:
	BinaryTree();
	~BinaryTree();
	void Insert(int);
	void PreOrderDisplay();		// Root, Left, Right
	void InOrderDisplay();		// Lest, Root, Right
	void PostOrderDisplay();	// Lest, Right, Root
	void LevelOrderDisplay();	// Level by level - queue based)
	unsigned int getSize();
	virtual void DisplayNode(Node &nd);
	void ClearFullTree();
   int DeleteNode(int val);
};

#endif