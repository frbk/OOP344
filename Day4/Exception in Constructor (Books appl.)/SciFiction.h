#ifndef SCIFICTION_H
#define SCIFICTION_H

#include "Book.h"

class SciFiction : public Book
{
public:
   SciFiction(char *Author, char *Title, char *Language, int NumberPG, int BIN, char *Name_Of_Borrower)
      : Book(Author, Title, Language, NumberPG, BIN, "Science Fiction", Name_Of_Borrower)
   {
      DaysToBorrow = 15;
   }
};

#endif
