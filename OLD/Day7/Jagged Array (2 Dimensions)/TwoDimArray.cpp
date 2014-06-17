#include <iostream>

#define  DYNAMIC_ARRAY

using namespace std;


class MyClass
{
   int Line,Col;

public:
   void setPosition(int i, int j)
   {
      Line=i;
      Col=j;
   }

   int getLine(void)
   {
      return Line;
   }

   int getCol(void)
   {
      return Col;
   }

   ~MyClass()
   {
      cout << "Destructor (" << Line << "," << Col << ")" << endl;
   }
};


int main()
{
   const int MaxLine=3;
   const int MaxCol=2;
   int i;

#ifdef  DYNAMIC_ARRAY
   MyClass **cls;
   cls = new (MyClass *[MaxLine]);
   cout << "We use Dynamic allocation for array of pointers" << endl;
#else
   MyClass *cls[MaxLine];
   cout << "We use Static allocation for array of pointers" << endl;
#endif

   for ( i= 0 ; i<MaxLine ; i++ )
   {
      cls[i] = new MyClass[MaxCol];
      for ( int j=0 ; j<MaxCol ; j++ )
         cls[i][j].setPosition(i,j);
   }

   for ( i= 0 ; i<MaxLine ; i++ )
   {
      for ( int j=0 ; j<MaxCol ; j++ )
         cout << "(" << cls[i][j].getLine() << cls[i][j].getCol() << ")  ";
      cout << endl;
   }

   for ( i= 0 ; i<MaxLine ; i++ )
   {
      delete [] cls[i];
   }

#ifdef  DYNAMIC_ARRAY
   delete [] cls;
#endif

   return (0);
}

