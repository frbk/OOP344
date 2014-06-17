#ifndef MYBASE_H
#define MYBASE_H

class MyBase
{
	int val;
public:
	MyBase(int val) {this->val=val; }
	virtual int getVal() const { return val; }
	virtual MyBase *getCopy() const { return new MyBase(*this); }
};

#endif
