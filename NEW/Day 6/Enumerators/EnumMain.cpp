#include <iostream>
using namespace std;

void main()
{
   enum sports {bascketball, football, hockey, baseball, soccer, volleyball};
   char *SportsName[] = {"bascketball","football","hockey","baseball","soccer","volleyball"};
   cout << "Basckeball Id=" << bascketball << endl;

   sports mySport;
   cout << "Hockey's Id=" << hockey << endl;
   mySport = hockey;
   cout << "My Sport's Id=" << mySport << endl;
/*
 Illegal opperations on enumerators:
   mySport = football + 2;
   mySport++;
   mySport--;
   mySport = 2;
*/

   // Legal Operations on enumerators:
   mySport = static_cast<sports>(hockey + 1);
   cout << "My Sport's Id=" << mySport << endl;
   if ( mySport >= soccer )
      cout << SportsName[mySport] << " is an European popular sport." << endl;
   else
      cout << SportsName[mySport] << " is a North American popular sport." << endl;

   mySport = static_cast<sports>(4);
   if ( mySport >= soccer )
      cout << SportsName[mySport] << " is an European popular sport." << endl;
   else
      cout << SportsName[mySport] << " is a North American popular sport." << endl;

   cout << "switch(mySport=" << mySport << ") corresponds to: ";
   switch(mySport)
   {
   case bascketball:
      cout << "bascketball" << endl;
      break;
   case football:
      cout << "football" << endl;
      break;
   case hockey:
      cout << "hockey" << endl;
      break;
   case baseball:
      cout << "baseball" << endl;
      break;
   case soccer:
      cout << "soccer" << endl;
      break;
   case volleyball:
      cout << "volleyball" << endl;
      break;
   }


   // Declaring variables when Defining the Enumeration Type
   enum courses {IPC144=3, OOP244, OOP344, LAST} PaulCourse, aCourse;
   PaulCourse = OOP244;
   cout << "OOP244 has the ID=" << OOP244 << endl;
   // Using loops with enumerators
   for ( aCourse = IPC144 ;
         aCourse < LAST ;
         aCourse=static_cast<courses>(aCourse+1) )
   {
      if ( aCourse == PaulCourse )
         break;
   }
   switch(aCourse)
   {
   case IPC144:
      cout << "Paul takes IPC144" << endl;
      break;
   case OOP244:
      cout << "Paul takes OOP244" << endl;
      break;
   case OOP344:
      cout << "Paul takes OOP344" << endl;
      break;
   }
}