#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Card.h"
using namespace std;

#define NR_OF_CARDS   52
#define SUITES        4
#define FACES         NR_OF_CARDS / SUITES
class DeckOfCards
{
   Card  cards[NR_OF_CARDS];
   string Faces[FACES];
   string Suites[SUITES];
   string Colors[2];
   union Card_U
   {
      Card  card;
      unsigned short Val;
   } uCard;

public:
   DeckOfCards()
   {
      string face[FACES] = {"A","2","3","4","5","6","7","8","9","10","J","D","K"};
      int i;
      for (i=0 ; i< FACES ; i++)
         Faces[i] = face[i];

      Suites[0] = "Diamond";
      Suites[1] = "Hart";
      Suites[2] = "Club";
      Suites[3] = "Spade";

      Colors[0] = "Red";
      Colors[1] = "Black";

      for (i = 0 ; i<NR_OF_CARDS ; i++)
      {
         cards[i].Face = i % FACES;
         cards[i].Suit = i % SUITES;
         cards[i].Color = i / 2;
      }
   }

   void Deal()
   {
      for(int i=0 ; i<NR_OF_CARDS ; i++)
      {
         uCard.card = cards[i];
         uCard.Val &= 0x007F;
         cout << setfill(' ');
         cout << setw(2) << Faces[cards[i].Face]
              << setw(8) << Suites[cards[i].Suit]
              << setw(8) << Colors[cards[i].Color]
              << setw(6) << "0x" << setw(2) << setfill('0') << hex << uCard.Val
              << endl;
      }
   }
};

#endif
