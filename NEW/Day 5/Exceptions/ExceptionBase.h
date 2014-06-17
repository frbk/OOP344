#ifndef EXCEPTIONBASE_H
#define EXCEPTIONBASE_H
#include <string>
using namespace std;

class ExceptionBase
{
	int code;
	string mess;
public:
	ExceptionBase(int cd, char *Mess) {code = cd; mess = Mess; }
	int getCode() { return code; }
	string getMess() { return mess; }
};

#endif
