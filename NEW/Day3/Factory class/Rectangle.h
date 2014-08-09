#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>
using namespace std;

#include "Shape.h"

class Rectangle : public Shape
{
   double Width, Hight;
protected:
   Rectangle (double xOrig, double yOrig, double w, double h)
      : Shape (xOrig, yOrig)
   {
      Width = w;
      Hight = h;
   }

   friend class FactoryShape;
public:
   string getType() {return "Rectangle"; }
   double getArea() {return Width * Hight; };
   double getPerimeter() {return 2*(Width+Hight); }
};

#endif
