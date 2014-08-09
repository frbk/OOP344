#include <iostream>
#include <math.h>

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
	unsigned int getSize() { return top+1; }
	T getObject(unsigned int ind) { return st[ind]; }
};


class Location
{
	double x,y;

public:
	Location() { x=y=0; }
	Location(double xP, double yP) { x=xP; y=yP; }
	double getX() { return x; }
	double getY() { return y; }
};


template <class T>
//class Polygon : public Stack<Location>
class Polygon : public Stack<T>
{
	friend ostream & operator <<(ostream &os, Polygon<T> &obj);
public:
	double getPerimeter()
	{
		Location  l1, l2;
		double peri = 0;
		if (getSize() <= 2) return (0);
		for (int i = 0 ; i<getSize()-1 ; i++)
		{
			l1 = getObject(i);
			l2 = getObject(i+1);
			peri += sqrt((l2.getX()-l1.getX())*(l2.getX()-l1.getX())
						+(l2.getY()-l1.getY())*(l2.getY()-l1.getY()));
		}
		l1 = getObject(0);
		peri += sqrt((l2.getX()-l1.getX())*(l2.getX()-l1.getX())
					+(l2.getY()-l1.getY())*(l2.getY()-l1.getY()));
		return peri;
	}
};

ostream & operator <<(ostream &os, Polygon<Location> &obj)
{
	Location l;
	cout << "Vertexes of Polygon:" << endl;
	for (int i = 0 ; i<obj.getSize() ; i++)
	{
		l = obj.getObject(i);
		os << "["<< l.getX() << "," << l.getY() << "]" <<endl;
	}
	return os;
}

void main()
{
	Polygon<Location> pol3;
	pol3.push(Location(2,2));
	pol3.push(Location(2,5));
	pol3.push(Location(6,2));
	cout << "Perimeter=" << pol3.getPerimeter() << endl;
	cout << pol3;
}
