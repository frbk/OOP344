#ifndef MYBASE_H
#define MYBASE_H

class MyBase
{
	int val;
public:
	MyBase(int val) {this->val=val; }
	virtual int getVal() { return val; }
};

#endif
