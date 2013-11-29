#include <iostream>

using namespace std;

const int MAX = 100;

template <class T>
class Stack
{
	T    st[MAX];
	int  top;
public:
	Stack() { top = -1; }
	int push(T  Val)
	{
		if (top==MAX)
			return 0;  // out of bound
		st[++top] = Val;
		return 1;
	}
	int pop(T  &Val)
	{
		if (top<0)
			return 0;  // out of bound
		Val = st[top--];
		return 1;
	}
};

void main()
{
	Stack<int>  iSt;
	iSt.push(4);
	iSt.push(5);
	iSt.push(7);
	iSt.push(8);
	iSt.push(9);

	int iObj;
	while(iSt.pop(iObj))
	{
		cout << "Pop element=" << iObj << endl;
	}
	cout << "End of <int> stack!" << endl;


	Stack<double>  dSt;
	dSt.push(4.44);
	dSt.push(5.55);
	dSt.push(7.77);
	dSt.push(8.88);
	dSt.push(9.99);

	double dObj;
	while(dSt.pop(dObj))
	{
		cout << "Pop element=" << dObj << endl;
	}
	cout << "End of <double> stack!" << endl;

	Stack<char *>  szSt;
	char *szObj;

   szObj = new char[26];
   strcpy(szObj, "aaaaaaaaaa");
	szSt.push(szObj);

   szObj = new char[26];
   strcpy(szObj, "bbbbbbbbbb");
	szSt.push(szObj);

   szObj = new char[26];
   strcpy(szObj, "ccccccccccc");
	szSt.push(szObj);

   szObj = new char[26];
   strcpy(szObj, "ddddddddddd");
	szSt.push(szObj);

   szObj = new char[26];
   strcpy(szObj, "eeeeeeeeeee");
	szSt.push(szObj);

	while(szSt.pop(szObj))
	{
		cout << "Pop element=" << szObj << endl;
      delete szObj;
	}
	cout << "End of <char *> stack!" << endl;
}
