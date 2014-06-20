#ifndef MYSTRING_H
#define MYSTRING_H

class MyString
{
   char *psz;
   void CopyString(const char *s);

public:
   MyString() throw();
   MyString(const char *) throw();
   MyString(const MyString &) throw();
   ~MyString() throw();
   const char * const getString() throw();
   int compare(const MyString &) throw();
   int compare(const char *) throw();
   MyString operator + (const MyString &) throw();
   MyString operator + (const char *) throw();
   friend MyString operator + (const char *sz, const MyString &o)  throw()
   {
	   MyString tmp(sz);
	   tmp += o;
	   return tmp;
   }
   MyString & operator += (const MyString &) throw();
   MyString & operator += (const char *) throw();
   MyString &operator = (const MyString &) throw();
   int operator == (const MyString &) throw();
   int operator <= (const MyString &) throw();
   int operator >= (const MyString &) throw();
   int operator < (const MyString &) throw();
   int operator > (const MyString &) throw();
};

#endif
