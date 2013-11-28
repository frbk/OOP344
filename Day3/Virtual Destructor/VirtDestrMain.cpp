#include <iostream>
#include "Shape.h"
#include "Square.h"
using namespace std;

int main()
{
   Square *sq = new Square(6);
   delete sq;

   Shape *sh = new Square(6);
   delete sh;
   return (0);
}
