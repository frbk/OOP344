#include <strstream>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

#define  SIZE_BUFF   1000

void main()
{
   char membuff[SIZE_BUFF];
   ostrstream  mem(membuff, SIZE_BUFF);

   const double PI=3.1415;
   const double Euler=2.7182818284;

   mem << "We place the entire output in memory." << endl;
   mem << "Then we will transfer the content of the memory to the standard output." << endl;
   mem << "Becoause less I/O operation this method is supposed to be faster than ";
   mem << " transfering each data element to the I/O." << endl;

   mem << endl;
   mem << "PI=" << PI << endl;
   mem << "Euler's constant (no precision set)=" << Euler << endl;
   mem << setprecision(15);
   mem << "Euler's constant (prexision set to 15)=" << Euler << endl;
   mem << "End of demo" << endl;
   mem << endl;
   mem << ends;  // End of string which is '\0'

//   cout << membuff;


   stringstream ss;
   // how to rmove spaces from a string
   string a, squeezeSp;
   ss << "abc klm   xyz  ";
   cout << "Before Squeezing Out Spaces: " << ss.str() << endl;
   while (ss.good())
   {
	   ss >> a;
	   squeezeSp.append(a);
   }
   cout << "Squeezed Out Spaces: " << squeezeSp << endl;

   ss.clear();
   // Converting strings to number and vice versa
   double f=12.34;
   ss << f;
   ss >> a;
   cout << "Convert Number= " << f << " to string:" << a << endl;
   ss.clear();
   a="56.78";
   ss << a;
   ss >> f;
   cout << "String: " << a << " to Number=" << f << endl;
   ss.clear();

   ss << mem;
   ss << 123.456789 << endl;
   ss << "We increase precision to 10 digits" << endl;
   ss << setprecision(10);
   ss << 123.456789 << endl;
   ss << "We first build the string stream.";
   ss << "Then we can convert it to a String" << endl;
   mem << ss.str();

   mem << ends;  // End of string which is '\0'
   cout << membuff;

   std::string s; 
   s = ss.str(); 
   cout << endl << "My string is: " << s << endl;
   cout << "Length of string is: " << s.length() << endl;

   cout << endl;
   stringstream ss2;
   ss2 << "stringstream may be used as a tool to convert  numeric to ASCII (instead of itoa(), sprintf(buff,<format>,123.456)" << endl;
   ss2 << 999;
   s = ss2.str();
   cout << s << endl;
}
