#ifndef  INNER_H
#define INNER_H

template <class L> class Outter;

template <class T>
class Inner
{
   T Value;
public:
   Inner(T val)  {this->Value = val;}
   friend class Outter<T>;
};

#endif
