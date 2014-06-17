#include <iostream>
using namespace std;


class UsingFriend
{
      int Val;
public:
      UsingFriend(int i) {Val = i; }
      int getVal() { return Val; }
      friend void Add(UsingFriend &o, int i) { o.Val += i ; }
      friend void Substract(UsingFriend &o, int i);
};
 
void Substract(UsingFriend &o, int i) { o.Val -= i ; }

void main()
{
      UsingFriend cls(2);
      cout << "Val = " << cls.getVal() << endl;
      Add(cls, 5);
      cout << "After Add Val = " << cls.getVal() << endl;
      Substract(cls,10);
      cout << "After Substract Val = " << cls.getVal() << endl;
}
