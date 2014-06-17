#include <iostream>
#include <string>
#include "MyClassTestException.h"
#include "Exception_1.h"
#include "Exception_2.h"
using namespace std;

void function_B(int ExceptionId)
{
   cout << "Function_B: entry" << endl;
   MyClassTestException cls4(4);
   if (ExceptionId == 4)
   {
      // The Code first digit is the Exception class identifier
      // and the second digit is the ExceptionId
      cout << "Throwing Exception_1 code=14 " << endl;
      throw Exception_1(14, "Exception thrown from function_B.");
   }
   if (ExceptionId == 5)
   {
      cout << "Throwing Exception_1 code=15 " << endl;
      throw Exception_1(15, "Exception thrown from function_B.");
   }
   cout << "Function_B: exits gratiously" << endl;
}

void function_A(int ExceptionId)
{
   try {
      cout << "Function_A: entry" << endl;
      MyClassTestException cls2(2);
      if (ExceptionId == 2)
      {
         cout << "Throwing Exception_2 code=22 " << endl;
         throw Exception_2(22, "Exception thrown from function_A.");
      }
      function_B(ExceptionId);
      MyClassTestException cls3(3);
      if (ExceptionId == 3)
      {
         cout << "Throwing Exception_2 code=23 " << endl;
         throw Exception_2(23, "Exception thrown from function_A.");
      }
      if (ExceptionId == 4)
      {
         cout << "Throwing ExceptionBase code=24 " << endl;
         throw ExceptionBase(24, "Exception thrown from function_A.");
      }
   }
   catch(Exception_1 e)
   {
      cout << "Catching Exception:" << e.getCode() << " in function_A.";
      if (e.getCode() == 14)
      {
         cout << "... and re-throwing it." << endl;
         throw e;
      }
      cout << endl;
   }
   cout << "Function_A: exits gratiously" << endl;
}

void main()
{
   try {
      int ExceptionId;
      cout << "Input the ExceptionId(1-6)= ";
      cin >> ExceptionId;
      MyClassTestException cls1(1);
      if (ExceptionId == 1)
      {
         cout << "Throwing ExceptionBase code=1 " << endl;
         throw ExceptionBase(1, "Exception thrown from main try block.");
      }
      function_A(ExceptionId);
   }
   catch(Exception_1 e)
   {
      cout << "Exception= " << e.getCode() << ": " << e.getMess() << endl;
   }
   catch(Exception_2 e)
   {
      cout << "Exception= " << e.getCode() << ": " << e.getMess() << endl;
   }
   catch(ExceptionBase e)
   {
      cout << "Exception= " << e.getCode() << ": " << e.getMess() << endl;
   }
}