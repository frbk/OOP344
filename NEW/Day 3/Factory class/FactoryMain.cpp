#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "FactoryShape.h"
using namespace std;


void DisplayShape(Shape *sh);

void main()
{
   Shape *sh;

   sh = FactoryShape::getShape("circle",-4, 4, 2);
   DisplayShape(sh);
   delete sh;

   sh = FactoryShape::getShape("Rectangle",5, 5, 4, 2);
   DisplayShape(sh);
   delete sh;

   sh = FactoryShape::getShape("square",4, -4, 2);
   DisplayShape(sh);
   delete sh;

   return;
}


void DisplayShape(Shape *sh)
{
   if (sh)
   {
      sh->DisplayInfo();
   }
   else
   {
      cout << "Unknown Shape" << endl;
   }
}
