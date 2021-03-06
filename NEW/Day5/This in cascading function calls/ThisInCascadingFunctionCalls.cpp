#include <iostream>
using namespace std;

class Calc
{
 private:
   int m_nValue;
 public:
    Calc() { m_nValue = 0; }
    Calc& Add(int nValue) { m_nValue += nValue; return *this; }
    Calc& Sub(int nValue) { m_nValue -= nValue; return *this; }
    Calc& Mult(int nValue) { m_nValue *= nValue; return *this; }
    int GetValue() { return m_nValue; }
};

void main()
{
   Calc cCalc;

   cout << "Value=" << cCalc.GetValue() << endl;

   cCalc.Add(5).Sub(3).Mult(4);

   cout << "Value=" << cCalc.GetValue() << endl;
}

