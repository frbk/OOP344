#include <iostream>
#include "BinaryTree.h"

using namespace std;

BinaryTree::BinaryTree()
{
	head = 0;
	size = 0;
   isDisplay = true;
}


BinaryTree::~BinaryTree()
{
   isDisplay = false;
	ClearFullTree();
}

void BinaryTree::ClearFullTree()
{
	ClearTree(head);
	head = 0;
}

void BinaryTree::ClearTree(Node *nd)
{
	if (nd)
	{
		PostOrder(nd->left);
		PostOrder(nd->right);
	}
}

void BinaryTree::Insert(int val)
{
	Node *nd = new Node(val);
	InsertNode(head, nd);
}

void BinaryTree::InsertNode(Node *tree, Node *nd)
{
   if (!nd)
      return;
	if (!head)
	{
		head = nd;
		size++;
      return;
	}
	if (nd->Value < tree->Value)
	{
		if (tree->left)
			InsertNode(tree->left, nd);
		else
		{
			tree->left = nd;
			size++;
		}
	}
	else if (nd->Value > tree->Value)
	{
		if (tree->right)
			InsertNode(tree->right, nd);
		else
		{
			tree->right = nd;
			size++;
		}
	}
}

void BinaryTree::PreOrder(Node *nd)		// Root, Left, Right
{
	if (nd)
	{
      DisplayNode(nd);
		PreOrder(nd->left);
		PreOrder(nd->right);
	}
}

void BinaryTree::InOrder(Node *nd)		// Left, Root, Right
{
	if (nd)
	{
		InOrder(nd->left);
      DisplayNode(nd);
		InOrder(nd->right);
	}
}

void BinaryTree::PostOrder(Node *nd)	// Left, Right, Root
{
	if (nd)
	{
		PostOrder(nd->left);
		PostOrder(nd->right);
      DisplayNode(nd);
	}
}
/*
void BinaryTree::LevelOrder(Node *nd)	// Level by level - queue based)
{
}
*/
unsigned int BinaryTree::getSize()
{
	return size;
}


void BinaryTree::PreOrderDisplay()		// Root, Left, Right
{
	PreOrder(head);
}

void BinaryTree::InOrderDisplay()		// Left, Root, Right
{
	InOrder(head);
}

void BinaryTree::PostOrderDisplay()		// Left, Right, Root
{
	PostOrder(head);
}

/*
void BinaryTree::LevelOrderDisplay()	// Level by level - queue based)
{
	LevelOrder(head);
}
*/

int BinaryTree::DeleteNode(int val)
{
   int ret;
   ret = SearchForNode(val, head, 0);
   if (!ret)
      return 0;
   if (!prevNd)                   // we delete the first node of the tree
   {
      head = aNd->left;
      InsertNode(head, aNd->right);
   }
   else if (prevNd->left == aNd)
   {
      prevNd->left = aNd->left;
      InsertNode(prevNd, aNd->right);
   }
   else
   {
      prevNd->right = aNd->right;
      InsertNode(prevNd, aNd->left);
   }
	delete aNd;
	size--;
   return 1;
}

int BinaryTree::SearchForNode(int val, Node *nd, Node *prevNd)
{
   int ret;
	if (nd->getValue() == val)
   {
      aNd = nd;
      this->prevNd = prevNd;
      return 1;
   }
   if (nd->left)
   {
      ret = SearchForNode(val, nd->left, nd);
      if (ret)
         return 1;
   }
   if (nd->right)
   {
      ret = SearchForNode(val, nd->right, nd);
      if (ret)
         return 1;
   }
   return 0;
}

void BinaryTree::DisplayNode(Node *nd)
{
	if (isDisplay)    // isDisplay is se to false in the destructor
		DisplayNode(*nd);
	else
		delete nd;
}

void BinaryTree::DisplayNode(Node &nd)
{
      cout << nd.Value << ", ";
}


void BinaryTree::reBalancing()
{
   arrInOrder = new Node *[size];
   iInOrder = 0;
   GetInOrder(head);
   cout << endl << "The array of inorder values is:" << endl;
   for (int i=0 ; i<size ; i++)
      cout << arrInOrder[i]->getValue() << ", ";
   cout << endl;
   head = 0;
   InsertMidValue(0, size-1);
   delete arrInOrder;
}

void BinaryTree::GetInOrder(Node *nd)		// Left, Root, Right
{
	if (nd)
	{
		GetInOrder(nd->left);
      arrInOrder[iInOrder++] = nd;
		GetInOrder(nd->right);
	}
}

void BinaryTree::InsertMidValue(int first, int last)
{
   if (first>last)
      return;
   int mid = first + (last-first)/2;
   cout << "Inserting " << arrInOrder[mid]->getValue() << endl;
   arrInOrder[mid]->left=0;
   arrInOrder[mid]->right=0;
   InsertNode(head, arrInOrder[mid]);
   InsertMidValue(first, mid-1);
   InsertMidValue(mid+1, last);
}
