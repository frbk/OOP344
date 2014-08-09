#ifndef EXCEPTION_1_H
#define EXCEPTION_1_H
#include <string>
#include "ExceptionBase.h"
using namespace std;

class Exception_1 : public ExceptionBase
{
   string type;
public:
	Exception_1(int cd, char *Mess)
      : ExceptionBase(cd, Mess)
   {
      type = "EXCEPTION_1";
   }
};

#endif
