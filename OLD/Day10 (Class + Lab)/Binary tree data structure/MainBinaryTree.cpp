#include <iostream>
#include "BinaryTree.h"

using namespace std;

void main()
{
	int n;
	BinaryTree bTree;
	char yn;
   int arr[] = {7,5,4,6,3,9,8,10,12,11,13};
   for (int i=0 ; i<sizeof(arr)/sizeof(int) ; i++)
		bTree.Insert(arr[i]);
/*
   do {
		cout << "Enter a number to insert in the BTree: ";
		cin >> n;

		bTree.Insert(n);
		cout << "Continue (Y/N)?:";
		cin >> yn;
	} while (yn=='Y' || yn=='y');
*/

	cout << "The BTree has " << bTree.getSize() << " objects" << endl;

	cout << endl << "Preorder:= <Root,Left,Right>" << endl;
	bTree.PreOrderDisplay();
	cout << endl << "Inorder:= <Left,Root,Right>" << endl;
	bTree.InOrderDisplay();
	cout << endl << "Postorder:= <Left,Right,Root>" << endl;
	bTree.PostOrderDisplay();


   do {
		cout << endl << "Enter the number to DELETE from the BTree: ";
		cin >> n;

		int ret = bTree.DeleteNode(n);
      if (ret)
      {
         cout << "Node " << n << " was deleted:" << endl;
         bTree.PreOrderDisplay();
         cout << endl;
      }
      else
         cout << "Bode " << n << " was not found" << endl;
		cout << "Continue to DELETE (Y/N)?:";
		cin >> yn;
	} while (yn=='Y' || yn=='y');

   cout << endl << "Clean the tree" << endl;
}