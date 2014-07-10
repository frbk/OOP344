#ifndef MYSTRING_H
#define MYSTRING_H

class MyString
{
   char *psz;
   void CopyString(char *s);

public:
   MyString();
   MyString(char *);
   MyString(MyString &);
   ~MyString();
   const char * const getString();
   int compare(MyString &);
   int compare(char *);
   MyString operator + (MyString &);
   MyString operator + (char *);
   MyString & operator += (MyString &);
   MyString & operator += (char *);
   MyString &operator = (MyString &);
   int operator == (MyString &);
   int operator <= (MyString &);
   int operator >= (MyString &);
   int operator < (MyString &);
   int operator > (MyString &);
};

#endif