#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>
#include "Shape.h"

using namespace std;

class Circle : public Shape
{
   double Radius;
   static const double PI;

   Circle (double xOrig, double yOrig, double Rad)
      : Shape (xOrig, yOrig)
   {
      Radius = Rad;
   }

   friend class FactoryShape;
public:
   double getArea() {return PI * Radius * Radius; }
   double getPerimeter() {return 2 * PI * Radius; }
   string getType() {return "Circle"; }
   string getDrawingPen() {return "Red"; }
};

#endif
