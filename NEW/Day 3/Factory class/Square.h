#ifndef SQUARE_H
#define SQUARE_H

#include <string>
using namespace std;

#include "Rectangle.h"

class Square : public Rectangle
{

   Square(double xOrig, double yOrig, double side)
      : Rectangle(xOrig, yOrig, side, side)
  {}

   friend class FactoryShape;
public:
   string getType() {return "Square"; }

};

#endif
