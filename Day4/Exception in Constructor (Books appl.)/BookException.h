#ifndef BOOKEXCEPTION_H
#define BOOKEXCEPTION_H

#include <string>
using namespace std;

class BookException
{
   string mess;
   int code;
public:
   BookException(char *str, int cd)
   {
      mess = str;
      code = cd;
   }
   string getMessage() { return mess; }
   int getCode() { return code; }
};

#endif
