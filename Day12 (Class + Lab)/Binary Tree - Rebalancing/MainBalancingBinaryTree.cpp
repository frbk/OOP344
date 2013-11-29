#include <iostream>
#include "BinaryTree.h"

using namespace std;

void main()
{
	BinaryTree bTree;

   int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
//   int arr[] = {7,5,4,6,3,9,8,10,12,11,13};
   for (int i=0 ; i<sizeof(arr)/sizeof(int) ; i++)
		bTree.Insert(arr[i]);

   cout << "The BTree has " << bTree.getSize() << " objects" << endl;

	cout << endl << "Preorder:= <Root,Left,Right>" << endl;
	bTree.PreOrderDisplay();
/*
	int n;
	char yn;
   do {
		cout << "Enter the number to DELETE from the BTree: ";
		cin >> n;

		int ret = bTree.DeleteNode(n);
      if (ret)
      {
         cout << "Node " << n << " was deleted:";
         bTree.PreOrderDisplay();
         cout << endl;
      }
      else
         cout << "Bode " << n << " was not found" << endl;
		cout << "Continue to DELETE (Y/N)?:";
		cin >> yn;
	} while (yn=='Y' || yn=='y');
*/
   bTree.reBalancing();
	cout << endl << "Preorder:= <Root,Left,Right>" << endl;
	bTree.PreOrderDisplay();
   cout << endl << "Clean the tree" << endl;
}