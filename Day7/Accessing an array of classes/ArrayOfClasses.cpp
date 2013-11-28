#include <iostream>
using namespace std;

class Employee
{
	int Id;
public:
   Employee()  {  cout << "Constructor Id unknown=" << Id << endl; }
   ~Employee() {  cout << "Destructor Id=" << Id << endl;  }
   void setId(int id)  { Id = id; }
   int getId() { return Id; }
};


int main()
{
   Employee  em[10];
   Employee  *p;
   int Len = sizeof(em) / sizeof(em[0]);
   int i;
   for (i=0 ; i<Len ; i++)
	   em[i].setId(i+1);

   cout << "Scanning the array of classes using a pointer" << endl;
   for (i=0, p=&em[0] ; i<Len ; i++, p++)
	   cout << p->getId() << endl;

   return (0);
}