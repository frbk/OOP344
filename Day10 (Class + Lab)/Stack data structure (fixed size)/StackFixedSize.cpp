#include <iostream>

using namespace std;

const int MAX = 100;

class Stack
{
	int  st[MAX];
	int  top;
public:
	Stack() { top = -1; }
	int push(int Val)
	{
		if (top==MAX)
			return 0;  // out of bound
		st[++top] = Val;
		return 1;
	}
	int pop(int &Val)
	{
		if (top<0)
			return 0;  // out of bound
		Val = st[top--];
		return 1;
	}
};

void main()
{
	Stack  st;
	st.push(4);
	st.push(5);
	st.push(7);
	st.push(8);
	st.push(9);

	int Obj;
	while(st.pop(Obj))
	{
		cout << "Pop element=" << Obj << endl;
	}
	cout << "End of stack!" << endl;
}
