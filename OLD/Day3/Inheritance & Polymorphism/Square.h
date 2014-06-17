#ifndef SQUARE_H
#define SQUARE_H

#include <string>
using namespace std;

#include "Rectangle.h"

class Square : public Rectangle
{
public:
   Square(double xOrig, double yOrig, double side)
      : Rectangle(xOrig, yOrig, side, side)
   {}

   string getType() {return "Square"; }

};

#endif
