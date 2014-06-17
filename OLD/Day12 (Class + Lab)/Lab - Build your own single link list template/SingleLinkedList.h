#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include "Node.h"

template <class L>
class SingleLinkedList
{
	Node<L> *root;
public:
//	SingleLinkedList();
//	~SingleLinkedList();
//	void AddNode(Node<L> *);
//	Node<L> *getFirstNode();
//	Node<L> *getNextNode(Node<L> *nd);
//	int deleteNode(L val);
   SingleLinkedList()
   {
	   root = 0;
   }
   
   ~SingleLinkedList()
   {
	   Node<L> *curr=root;
	   Node<L> *next;

	   while(curr)
      {
		   next = curr->next;
		   delete curr;
		   curr = next;
      }
   }
   void AddNode(Node<L> *nd)
   {
	   if (!root)
      {
		   root = nd;
		   return;
      }
	   nd->next = root;
	   root = nd;
   }
   Node<L> *getFirstNode()
   {
	   return root;
   }

   Node<L> *getNextNode(Node<L> *nd)
   {
	   return nd->next;
   }

   int deleteNode(L val)
   {
	   Node<L> *prev=0;
	   for (Node<L> *nd=getFirstNode() ; nd ; nd=getNextNode(nd))
      {
		   if (nd->getValue() == val)
         {
			   if (!prev)  // we delete the first node
            {
				   root = nd->next;
				   delete nd;
				   return 1;
            }
			   else
            {
				   prev->next = nd->next;
				   delete nd;
				   return 1;
            }
         }
		   else
         {
			   prev = nd;
         }
      }
	   return 0;
   }

};

#endif