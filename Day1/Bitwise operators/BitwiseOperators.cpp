#include <iostream>
#include <string>
using namespace std;

class Bitwise
{
 public:

   static string toBinary(char Val)
   {
      int mask;
      string str;
      for ( mask=0x80 ; mask ; mask>>=1 )
         str.append((Val & mask) ? "1" : "0");
      return str;
   }

   static char rol(char Val, unsigned int count = 1)
   {
      count = count % 8;
      for ( ; count ; count-- )
         Val = (Val << 1) | ((Val & 0x80) ? 1 : 0);
      return Val;
   }

   static char ror(char Val, unsigned int count = 1)
   {
      count = count % 8;
      for ( ; count ; count-- )
         Val = ((Val >> 1) & 0x07F) | ((Val & 0x01) ? 0x80 : 0);
      return Val;
   }
};

void main()
{
   int Val;

   Val = 1;
   cout << "Val= " << Val << " Binary= " << Bitwise::toBinary(Val) << endl;
   Val = Val << 3;
   cout << "Shift left by 3 bits Val= " << Val << " Binary= " << Bitwise::toBinary(Val) << endl;
   Val = Val >> 1;
   cout << "Shift right by 1 bit Val= " << Val << " Binary= " << Bitwise::toBinary(Val) << endl;

   Val = 0x69;
   cout << hex;
   cout << endl << "Hex Val= " << Val << endl;
   cout << "Hex Val & 0x28= " << (Val & 0x28) << endl;
   Val = Val & 0xF7;
   cout << "Hex Val= " << Val << endl;
   cout << "Hex Val & 0x28= " << (Val & 0x28) << endl;
   Val = Val | 0x80;
   cout << "Hex Val= " << Val << endl;
   cout << "Hex Val & 0x28= " << (Val & 0x28) << endl;

   Val = 6;
   // we need to reset back to Decimal
   cout << endl << "Dec Val= " << dec << Val << endl;
   cout << "Hex Val= " << hex << Val << endl;
   cout << "Oct Val= " << oct << Val << endl;
   cout << "Bin Val= " << Bitwise::toBinary(Val) << endl;

   Val = 12;
   // we need to reset back to Decimal
   cout << endl << "Dec Val= " << dec << Val << endl;
   cout << "Hex Val= " << hex << Val << endl;
   cout << "Oct Val= " << oct << Val << endl;
   cout << "Bin Val= " << Bitwise::toBinary(Val) << endl;

   Val = 0xD3;
   cout << endl << "Bin Val= " << Bitwise::toBinary(Val) << endl;
   cout << "Rotation Left" << endl;
   Val = Bitwise::rol(Val);
   cout << "Bin Val= " << Bitwise::toBinary(Val) << endl;

   Val = 0xD3;
   cout << endl << "Bin Val= " << Bitwise::toBinary(Val) << endl;
   cout << "Rotation Right" << endl;
   Val = Bitwise::ror(Val, 3);
   cout << "Bin Val= " << Bitwise::toBinary(Val) << endl;

   Val = 0xC0000000;
   cout << "signed Val " << hex << Val << endl;
   Val >>= 1;
   cout << "After Right Shift " << hex << Val << endl;

   unsigned int uVal = 0xC0000000;
   cout << "unsigned uVal " << hex << uVal << endl;
   uVal >>= 1;
   cout << "After Right Shift " << hex << uVal << endl;

   Val = 0xA0000000;
   cout << "signed Val " << hex << Val << endl;
   Val <<= 1;
   cout << "After Left Shift " << hex << Val << endl;

   uVal = 0xA0000000;
   cout << "unsigned uVal " << hex << uVal << endl;
   uVal <<= 1;
   cout << "After Left Shift " << hex << uVal << endl;
}
