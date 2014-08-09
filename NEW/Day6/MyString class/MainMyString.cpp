#include <iostream>
#include "MyString.h"
using namespace std;


void main()
{
   MyString s1("My First String");
   MyString s2(s1);
   MyString s3;
   MyString s4(" Other String");

   cout << s1.getString() << endl;
   cout << s2.getString() << endl;

   s3 = s2;
   cout << s3.getString() << endl;

   s3 = s1 + s4;
   cout << s3.getString() << endl;
   s3 += " Third string";
   cout << s3.getString() << endl;

   s3 = "After promotion: " + s1;    // promoting a char array
   cout << s3.getString() << endl;

   s1 = s2 = s3;
   cout << s1.getString() << endl;
   cout << s2.getString() << endl;

   cout << "operator == result: " << (s3 == s1) << endl;
   cout << "operator <= result: " << (s3 <= s1) << endl;
   cout << "operator >= result: " << (s3 >= s1) << endl;
}
