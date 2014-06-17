
#include "SingleLinkedList.h"

#include <string.h>
#include <iostream>
using namespace std;

SingleLinkedList::SingleLinkedList()
{
	root = 0;
}

SingleLinkedList::~SingleLinkedList()
{
	
	Student *curr = root;
	Student *next;

	while (curr)
	{
		next = curr->next;
		delete curr;
		curr = next;
	}
}
void SingleLinkedList::AddNode(Student *node){
	if (!root){
		root = node;
		return;
	}
	node->next = root;
	root = node;
}
Student *SingleLinkedList::getFirstNode()
{
	return root;
}


Student *SingleLinkedList::getNextNode(Student *node)
{
	return node->next;
}
void SingleLinkedList::BubbleSort(){
	int flagSwap;
	Student *stTemp;
	Student *st1Node, *st2Node;
	Student *st1, *st2;
	flagSwap = 1;
	while ( flagSwap )
   {
      flagSwap = 0;
      st1Node = getFirstNode();
      if (!st1Node)
         return;
      st2Node = getNextNode(st1Node);
      if (!st2Node)
         return;
      for ( ; st2Node ; st1Node=st2Node, st2Node=getNextNode(st1Node) )
      {
      	 st1 = st1Node;
      	 st2 = st2Node;
        // cout <<st1->getFirstName() <<" "<<st2->getFirstName()<<" "<<strcmp(st1->getFirstName(),st2->getFirstName())<< endl;
      	
       if(strcmp(st1->getFirstName(),st2->getFirstName()) < 0){
				//cout << st1Node->getFirstName() <<"<"<< st2Node->getFirstName() <<endl;
				//stTemp = st1 ->Student;
				//st1->Student = st2->Student;
				//st2->Student = stTemp->Student;
       	 		cout << st1->getFirstName()<< " "<< st2->getFirstName() << endl;
				stTemp = st1;
				st1 = st2;
				st2= stTemp;
				cout << st1->getFirstName()<< " "<< st2->getFirstName() << endl;
				cout << "                 " << endl;
		}
      }
   }
}



	//while(flagSwap){
	//	flagSwap = 0;
		/*
		st1Node = getFirstNode();
		if(!st1Node){
			return;
		}
		st2Node = getNextNode(st1Node);
		if(!st2Node){
			return;
		}*/
		/*
		for (st1Node=getFirstNode() ; st1Node ; st1Node=getNextNode(st1Node)){
			st2Node = getNextNode(st1Node);
			if(!st2Node){
				return;
			}
			cout << "! "<<st1Node->getFirstName() <<" "<< st2Node->getFirstName() <<endl;

			if(strcmp(st1Node->getFirstName(),st2Node->getFirstName()) == 0){
			//	cout << st1Node->getFirstName() <<"="<< st2Node->getFirstName() <<endl;
			}
			if(strcmp(st1Node->getFirstName(),st2Node->getFirstName()) < 0){
		//		cout << st1Node->getFirstName() <<"<"<< st2Node->getFirstName() <<endl;
				stTemp = st1Node;
				st1Node = st2Node;
				st2Node = stTemp;
			//	cout << "<" << endl;
			}
			
		}*/
		/*
		cout << "After" << endl;
		for (st1Node=getFirstNode() ; st1Node ; st1Node=getNextNode(st1Node)){
			
			cout << st1Node->getFirstName() << endl;
		}
		/*
		for(; st2Node ; st1Node=st2Node, st2Node=getNextNode(st1Node)){
			if(strcmp(st1Node->getFirstName(),st2Node->getFirstName()) == 0){
				cout << "equal" << endl;
				flagSwap = 1;
			}
			if(strcmp(st1Node->getFirstName(),st2Node->getFirstName()) > 0){
				stTemp = st1Node;
				st1Node = st2Node;
				st2Node = stTemp;
				cout << ">" << endl;
				flagSwap = 1;
				//break;
			}
// 0 =
// > 0 2 > 1
// <0  2 < 1 
		}
		*/
/*	}
}
*/
/*
void StudentsSingleLinkedList::BubbleSort()
{
   int flagSwap;
   Student *stTemp;
   StudentNode *st1Node, *st2Node;

   flagSwap = 1;
   while ( flagSwap )
   {
      flagSwap = 0;
      st1Node = getFirstNode();
      if (!st1Node)
         return;
      st2Node = getNextNode(st1Node);
      if (!st2Node)
         return;
      for ( ; st2Node ; st1Node=st2Node, st2Node=getNextNode(st1Node) )
      {
         if ( *(st1Node->Value) > *(st2Node->Value) )
         {
            stTemp = st1Node->Value;
            st1Node->Value = st2Node->Value;
            st2Node->Value = stTemp;
            flagSwap = 1;
         }
      }
   }
}
*/