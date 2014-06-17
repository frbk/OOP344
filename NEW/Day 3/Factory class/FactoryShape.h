#ifndef FACTORYSHAPE_H
#define FACTORYSHAPE_H

#include <string>
#include <cctype>       // character handling library
#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"

using namespace std;

class FactoryShape
{
 public:
   static Shape *getShape(string sh, double xOrig, double yOrig, double w, double h)
   {
      ToUpper(sh);
      if (sh.compare("RECTANGLE") == 0)
      {
        return new Rectangle(xOrig, yOrig, w, h);
      }
      else
        return 0;
   }

   static Shape *getShape(string sh, double xOrig, double yOrig, double len)
   {
      ToUpper(sh);
      if (sh.compare("CIRCLE") == 0)
      {
        return new Circle(xOrig, yOrig, len);
      }
      else if (sh.compare("SQUARE") == 0)
      {
        return new Square(xOrig, yOrig, len);
      }
      else
        return 0;
   }

private:
   static void ToUpper(string &sh)
   {
      for (int i=0 ; i<sh.length() ; i++)
      sh[i] = toupper(sh[i]);
   }
};

#endif