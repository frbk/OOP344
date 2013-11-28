#ifndef SQUARE_H
#define SQUARE_H
#include <string>

using namespace std;

class Square : public Shape
{
   double Side;

public:

   Square(double Side, double x=0, double y=0) :
            Shape("Square")
   {
      this->Side = Side;
      xCen = x;
      yCen = y;
   }

   virtual double getArea()
   {
      return Side * Side;
   }

   virtual double getPerimeter()
   {
      return 4 * Side;
   }

   virtual void Draw()
   {
      cout << "We draw the " << getType().data()
           << " with center"
           << " x=" << xCen
           << " y=" << yCen
           << " and Side=" << Side
           << endl;
   }

   ~Square()
   {
      cout << "~Square destructor" << endl;
   }
};

#endif