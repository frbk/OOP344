#ifndef CARD_H
#define CARD_H

struct Card
{
   unsigned short Face : 4;
   unsigned short Suit : 2;
   unsigned short Color : 1;
   unsigned short Filler : 9;
};

#endif