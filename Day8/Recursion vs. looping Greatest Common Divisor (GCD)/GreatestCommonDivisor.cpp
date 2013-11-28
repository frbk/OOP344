#include <iostream>
using namespace std;

int GCD_Loop(int n1, int n2);
int GCD_Recursive(int n1, int n2);

void main()
{
   int n1, n2;
   n1 = 210;
   n2 = 858;
   cout << "GCD_Loop(" << n1 << "," << n2 << ")=" << GCD_Loop(n1, n2) << endl;
   cout << "GCD_Recursive(" << n1 << "," << n2 << ")=" << GCD_Recursive(n1, n2) << endl;
}

int GCD_Loop(int n1, int n2)
{
   int temp;
   int reminder;
   if ( n2 > n1 )
   {
      temp = n1;
      n1 = n2;
      n2 = temp;
   }
   do {
      reminder = n1 % n2;
      n1 = n2;
      n2 = reminder;
   } while (reminder);
   return n1;
}

int GCD_Recursive(int n1, int n2)
{
   int temp;
   if ( n2 > n1 )
   {
      temp = n1;
      n1 = n2;
      n2 = temp;
   }
   if ( !n2 ) return n1;
   return GCD_Recursive(n2, n1%n2);

   return n1;
}
