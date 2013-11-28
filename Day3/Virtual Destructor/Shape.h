#ifndef SHAPE_H
#define SHAPE_H
#include <string>

using namespace std;

class Shape
{
   string Color;
   string Type;

protected:

   double xCen;
   double yCen;

public:

   Shape(char *Type="Unknown")
   {
      this->Type=Type;
      Color = "Black";
   }

   virtual double getArea() = 0;
   virtual double getPerimeter() = 0;
   virtual void Draw() = 0;

   void setColor(char *color)
   {
      Color = color;
   }

   string getColor(void)
   {
      return Color;
   }

   string getType()
   {
      return Type;
   }

   void setTranslation(double x, double y)
   {
      xCen = x;
      yCen = y;
   }

// Without 'virtual', in polymorphism the destructor of the
// derived (extended) class is not executed
//   ~Shape()
   virtual ~Shape()
   {
      cout << "~Shape destructor" << endl;
   }
};

#endif