#include <iostream>
#include <iomanip>
#include "StudentsSingleLinkedList.h"
#include "StudentNode.h"

using namespace std;

void main()
{
	int n;
	StudentNode  *node;
	StudentNode *nd;
	StudentsSingleLinkedList lList;
   char Fn[30], Ln[30];
   unsigned int Id;
	char yn;

	do {
		cout << "Enter a new Student information: " << endl;
      cout << "First Name: ";
      cin >> Fn;
      cout << "Last Name: ";
      cin >> Ln;
      cout << "Student's ID: ";
		cin >> Id;

		node = new StudentNode(new Student(Fn, Ln, Id));
		lList.AddNode(node);
		cout << "Continue (Y/N)?: ";
		cin >> yn;
	} while (yn=='Y' || yn=='y');

	for (nd=lList.getFirstNode() ; nd ; nd=lList.getNextNode(nd))
	{
		cout << nd->getValue() << ", ";
//		cout << setw(35) << nd->getValue().getFN() << setw(35) << nd->getValue().getLN() << setw(10) << nd->getValue().getId() << endl;;
	}

	cout << "Delete Student with ID= ";
	cin >> n;
	int del=lList.deleteNodeByID(n);
	if (!del)
		cout << "Node not found" << endl;
	else
		cout << "Node was deleted" << endl;

	for (nd=lList.getFirstNode() ; nd ; nd=lList.getNextNode(nd))
	{
		cout << nd->getValue() << ", ";
//		cout << setw(35) << nd->getValue().getFN() << setw(35) << nd->getValue().getLN() << setw(10) << nd->getValue().getId() << endl;;
/*
  Lab (in class) - Solution:
   1)
      Complete the code to replace the previous line with the following one:
		cout << nd->getValue() << ", ";
*/
   }

/*
   2)
      Using a sorting method you learned, order in ascending order the Students LinkList
      based on LastName + FirstName. The approach will be discussed with the teacher.
*/
   lList.BubbleSort();
   cout << "The Link List After Sorting:" << endl;
	for (nd=lList.getFirstNode() ; nd ; nd=lList.getNextNode(nd))
	{
		cout << nd->getValue() << ", ";
   }
	cout << endl;
}