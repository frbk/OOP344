#ifndef VARIABLETEMPLATE_H
#define VARIABLETEMPLATE_H

template <class T>
class Variable
{
	T  val;
public:
	Variable(T v) { val = v; }
	T getVal() { return val; }
	unsigned int getSize() {return sizeof(val); }
};

#endif