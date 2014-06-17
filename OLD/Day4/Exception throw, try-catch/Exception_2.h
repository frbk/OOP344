#ifndef EXCEPTION_2_H
#define EXCEPTION_2_H
#include <string>
#include "ExceptionBase.h"
using namespace std;

class Exception_2 : public ExceptionBase
{
   string type;
public:
	Exception_2(int cd, char *Mess)
      : ExceptionBase(cd, Mess)
   {
      type = "EXCEPTION_2";
   }
};

#endif
