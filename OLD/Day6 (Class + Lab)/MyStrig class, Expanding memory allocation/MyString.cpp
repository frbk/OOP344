#include <string.h>
#include "MyString.h"

void MyString::CopyString(char *s)
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

MyString::MyString()
{
   psz = 0;
   CopyString(0);
}

MyString::MyString(char *s)
{
   psz = 0;
   CopyString(s);
}


MyString::MyString(MyString &a)
{
   psz = 0;
   CopyString(a.psz);
}


MyString::~MyString()
{
   delete psz;
}


const char * const MyString::getString()
{
   return psz;
}

int MyString::compare(MyString &a)
{
   return strcmp(psz,a.psz);
}

int MyString::compare(char *s)
{
   if (s)
      return strcmp(psz,s);
   else
      return 1;
}

MyString MyString::operator + (MyString &a)
{
   char *tmp = new char[strlen(psz)+strlen(a.psz)+1];
   strcpy(tmp,psz);
   strcat(tmp,a.psz);
   MyString str(tmp);
   delete tmp;
   return str;
}

MyString MyString::operator + (char *s)
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

MyString & MyString::operator += (MyString &a)
{
   char *tmp = new char[strlen(psz)+strlen(a.psz)+1];
   strcpy(tmp,psz);
   strcat(tmp,a.psz);
   delete psz;
   psz = tmp;
   return *this;
}

MyString & MyString::operator += (char *s)
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

MyString & MyString::operator = (MyString &a)
{
   CopyString(a.psz);
   return *this;
}

int MyString::operator == (MyString &a)
{
   return !compare(a);
}

int MyString::operator <= (MyString &a)
{
   int ret = compare(a);
   if ( ret == -1 || ret == 0 )
      return 1;
   else
      return 0;
}

int MyString::operator >= (MyString &a)
{
   int ret = compare(a);
   if ( ret == 1 || ret == 0 )
      return 1;
   else
      return 0;
}

int MyString::operator < (MyString &a)
{
   int ret = compare(a);
   if ( ret == -1 )
      return 1;
   else
      return 0;
}

int MyString::operator > (MyString &a)
{
   int ret = compare(a);
   if ( ret == 1 )
      return 1;
   else
      return 0;
}
