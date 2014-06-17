#include<windows.h>
#include <stdio.h>
#include <conio.h>  /* needed for kbhit and getch */
#include <iostream>
using namespace std;

/*
  How to display at a certain position on the screen:
   #include <windoes.h>
      coord.X = 10;
      coord.Y = 30;
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
      cout << "aaaaaaaaaaaaaaaaaaaaaaaaa" << flush;
*/

struct kbBtn
{
   kbBtn() {}
   kbBtn(unsigned char ch1, unsigned char ch2 = 0)
   {
      this->ch1 = ch1;
      this->ch2 = ch2;

      unsigned short uni = 256*ch1 | ch2;
      printf("uni = %0x\n", uni);
      switch(uni)
      {
      case 0xE048:
         strcpy(Name, "ArrUP");
         break;
      case 0xE04D:
         strcpy(Name, "ArrRI");
         break;
      case 0xE050:
         strcpy(Name, "ArrDN");
         break;
      case 0xE04B:
         strcpy(Name, "ArrLF");
         break;
      case 0xE053:
         strcpy(Name, "DEL");
         break;
      case 0xE049:
         strcpy(Name, "PgUP");
         break;
      case 0xE051:
         strcpy(Name, "PgDN");
         break;
      case 0xE04F:
         strcpy(Name, "END");
         break;
      case 0xE047:
         strcpy(Name, "HOME");
         break;
      case 0x0800:
         strcpy(Name, "BckSp");
         break;
      case 0x1A00:
         strcpy(Name, "CtrlZ");
         break;
      default:
         strcpy(Name, "ALFNUM");
         break;
      }
   }
   char ch1, ch2;
   char Name[10];
};

kbBtn getStrike(unsigned char ch1, unsigned char ch2 = 0);

void main()
{
     int  ch1, ch2;
     kbBtn  btn;
    
    ch1 = -1;
    while (ch1 != 0x1B)              /* watch for an ESC */
    {
        if (kbhit())                /* check for a keystroke */
        {
            ch1 = getch();           /* get the key */
            if (ch1 == 0 || ch1 == 0xE0)            /* if it's 0... */
            {
               ch2 = getch();       /* get the next key */
               btn = getStrike(ch1, ch2);
            }
            else
            {
               btn = getStrike(ch1);
            }
            printf("\n");
        }
        Sleep(200);
    }
}


kbBtn getStrike(unsigned char ch1, unsigned char ch2)
{
   if (ch2 == -1)
   {
      printf("Function 1  %02X", ch1);
      if (isprint(ch1))
         printf("  /  %c", ch1);
   }
   else
   {
      printf("Function 2  %02X", ch2);
   }
   kbBtn btn(ch1,ch2);
   printf("Button= %s\n", btn.Name);
   return btn;
}
