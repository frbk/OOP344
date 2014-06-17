#include <iostream>
using namespace std;

class Student
{
   int StudentId;
   char *FirstName;
   Student &operator=(Student &);

public:
   Student(char *fn, int Id)
   {
      FirstName = new char[strlen(fn)+1];
      strcpy(FirstName, fn);
      StudentId = Id;
      cout << "Student Constructor ID=" << StudentId << endl;
   }

   Student(Student &st)
   {
      // Breakpoint
      FirstName = new char[strlen(st.FirstName)+1];
      strcpy(FirstName, st.FirstName);
      StudentId = st.StudentId;
      cout << "Student Copy Constructor ID=" << StudentId << endl;
   }

   ~Student()
   {
      cout << "Destructor :=" << FirstName << " / " << StudentId << endl;
      // Breakpoint
      delete FirstName;
   }

   char *getFirstName()  {return FirstName; }
   int getStudentId() {return StudentId; }
   void setStudentId(int id) { StudentId = id; }
};

class StudentSP
{
   Student *st;

public:
   StudentSP(Student *st)
   {
      cout << "SP constructor" << endl;
      this->st = st;
   }

   StudentSP(StudentSP &sp)
   {
      // Breakpoint
      cout << "SP Copy Constructor" << endl;
      st = new Student(*sp.st);
      cout << st->getFirstName() << " : " << st->getStudentId() << " (COPY)" << endl;
   }
   StudentSP &operator=(StudentSP &sp)
   {
      delete st;
      // Breakpoint
      cout << "SP operator =" << endl;
      st = new Student(*sp.st);
      cout << st->getFirstName() << " : " << st->getStudentId() << " (COPY =)" << endl;
   }

   ~StudentSP()
   {
      // Breakpoint
      cout << "SP Destructor" << endl;
      delete st;
   }

   Student *operator->()
   {
      return st;
   }
};

StudentSP function(StudentSP sp)
{
   // Breakpoint
   cout << "Entered Function" << endl;
   sp->setStudentId(555);
   return sp;
}

void main()
{
   // Breakpoint
   StudentSP st1(new Student("Mark", 123));
   cout << st1->getFirstName() << " : " << st1->getStudentId() << endl;
   StudentSP st2 = function (st1);
   // Breakpoint
   cout << "Exit Function" << endl;
   cout << st2->getFirstName() << " : " << st2->getStudentId() << endl;
   // Breakpoint
   /*
   Do not pass to the Wrapper (Smart Pointer) a pointer to the stack or to a static instance.
   Pass only pointer to objects on the Heap
   */
}