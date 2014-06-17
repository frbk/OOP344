#ifndef LEAKINGVLASS_H
#define LEAKINGVLASS_H

class LeakingClass
{
   char *szArr;
public:
   LeakingClass();
   LeakingClass(char *sz);
   ~LeakingClass();
   LeakingClass &operator =(LeakingClass &o);
};

#endif