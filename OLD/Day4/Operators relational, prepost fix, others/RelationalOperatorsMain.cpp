#include <iostream>
#include "Timestamp.h"

using namespace std;

void main()
{
   Timestamp t1(2011,02,13,14,45,27);
   Timestamp t2(2011,02,14,14,45,27);

   if (t1 < t2)
      cout << "t1 < t2" << endl;
   else
      cout << "t1 >= t2" << endl;

   cout << "t1= " << t1 << endl;
   cout << "t2= " << t2 << endl;
   t1++;
   Timestamp t3;
   t3 = t2 + 3;
   cout << "t1= " << t1 << endl;
   cout << "t3= " << t3 << endl;
   Timestamp t4 = t3 - t2;
   cout << "t3 - t2 = " << t4 << endl;
   t4 = t2 - t1;
   cout << "t2 - t1 = " << t4 << endl;

}
