#include "iostream"
#include "Outter.h"
using namespace std;

void main()
{
   Outter<int>  out;
   Inner<int>  a(1);
   Inner<int>  b(2);
   Inner<int>  c(3);
   Inner<int>  d(4);
   out.addInnerValue(a);
   out.addInnerValue(b);
   out.addInnerValue(c);
   out.addInnerValue(d);
   for (int i = 0 ; i<10 ; i++)
      cout << out[i] << ", ";    // invoking "operator []"
   cout << endl;

   cout << out;   // invoking "operator <<"
}
