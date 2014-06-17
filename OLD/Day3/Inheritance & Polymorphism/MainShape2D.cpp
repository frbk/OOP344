#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"

void main()
{
   int i;
   Shape *sh[3];
   sh[0] = new Rectangle(5, 5, 4, 2);
   sh[1] = new Circle(-4, 4, 2);
   sh[2] = new Square(4, -4, 2);

   for ( i=0 ; i<3 ; i++)
   {
      sh[i]->DisplayInfo();
   }
   for ( i=0 ; i<3 ; i++)
   {
      delete sh[i];
   }
}
