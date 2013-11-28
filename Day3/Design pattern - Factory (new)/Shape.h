#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string.h>
using namespace std;

class Shape
{
   double xOrig, yOrig;
protected:
   Shape(double x, double y)
   {
      xOrig = x;
      yOrig = y;
   }

   friend class FactoryShape;
public:
   virtual double getArea() = 0;
   virtual double getPerimeter() = 0;
   virtual string getType() = 0;
   virtual string getDrawingPen() {return "Black"; }
   void DisplayInfo()
   {
      cout << endl << "Figure: " << getType().data() << endl;
      cout << "Origin: {" << xOrig << ", " << yOrig << "}" << endl;
      cout << "Area: " << getArea() << endl;
      cout << "Perimeter: " << getPerimeter() << endl;
      cout << "Drawing pen: " << getDrawingPen().data() << endl;
      cout << endl;
   }
};

#endif