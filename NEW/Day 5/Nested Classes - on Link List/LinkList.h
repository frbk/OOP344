#ifndef LINKLIST_H
#define LINKLIST_H
#include <iostream>
#include <new>

using namespace std;

class LinkList
{
	class Node;
	Node *head_;
    void Clean();
    void MakeCopy(const LinkList &ll) throw(bad_alloc);
public:
	LinkList() throw();
	LinkList(const LinkList &) throw(bad_alloc);
	~LinkList() throw();
	LinkList &operator=(const LinkList &) throw(bad_alloc);
	void Add(int v) throw(bad_alloc);
	void Print(ostream &os) const throw();
	friend ostream &operator <<(ostream &os, LinkList &ll) throw();
};


class LinkList::Node
{
	int  val;
	Node *next_;
	Node(int v, Node *next) throw();
	friend class LinkList;
};

#endif
