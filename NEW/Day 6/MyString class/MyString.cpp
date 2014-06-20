#include <string.h>
#include "MyString.h"

void MyString::CopyString(const char *s) throw()
{
   delete psz;
   if (s)
   {
      psz = new char[strlen(s)+1];
      strcpy(psz,s);
   }
   else
   {
      psz = new char[1];
      psz[0]=0;
   }
}

MyString::MyString() throw()
{
   psz = 0;
   CopyString(0);
}

MyString::MyString(const char *s) throw()
{
   psz = 0;
   CopyString(s);
}


MyString::MyString(const MyString &a) throw()
{
   psz = 0;
   CopyString(a.psz);
}


MyString::~MyString() throw()
{
   delete psz;
}


const char * const MyString::getString() throw()
{
   return psz;
}

int MyString::compare(const MyString &a) throw()
{
   return strcmp(psz,a.psz);
}

int MyString::compare(const char *s) throw()
{
   if (s)
      return strcmp(psz,s);
   else
      return 1;
}

MyString MyString::operator + (const MyString &a) throw()
{
   char *tmp = new char[strlen(psz)+strlen(a.psz)+1];
   strcpy(tmp,psz);
   strcat(tmp,a.psz);
   MyString str(tmp);
   delete tmp;
   return str;
}

MyString MyString::operator + (const char *s) throw()
{
   if ( !s )
      return *this;
   char *tmp = new char[strlen(psz)+strlen(s)+1];
   strcpy(tmp,psz);
   strcat(tmp,s);
   MyString str(tmp);
   delete tmp;
   return str;
}

MyString & MyString::operator += (const MyString &a) throw()
{
   char *tmp = new char[strlen(psz)+strlen(a.psz)+1];
   strcpy(tmp,psz);
   strcat(tmp,a.psz);
   delete psz;
   psz = tmp;
   return *this;
}

MyString & MyString::operator += (const char *s) throw()
{
   if ( !s )
      return *this;
   char *tmp = new char[strlen(psz)+strlen(s)+1];
   strcpy(tmp,psz);
   strcat(tmp,s);
   delete psz;
   psz = tmp;
   return *this;
}

MyString & MyString::operator = (const MyString &a) throw()
{
   CopyString(a.psz);
   return *this;
}

int MyString::operator == (const MyString &a) throw()
{
   return !compare(a);
}

int MyString::operator <= (const MyString &a) throw()
{
   int ret = compare(a);
   if ( ret == -1 || ret == 0 )
      return 1;
   else
      return 0;
}

int MyString::operator >= (const MyString &a) throw()
{
   int ret = compare(a);
   if ( ret == 1 || ret == 0 )
      return 1;
   else
      return 0;
}

int MyString::operator < (const MyString &a) throw()
{
   int ret = compare(a);
   if ( ret == -1 )
      return 1;
   else
      return 0;
}

int MyString::operator > (const MyString &a) throw()
{
   int ret = compare(a);
   if ( ret == 1 )
      return 1;
   else
      return 0;
}
