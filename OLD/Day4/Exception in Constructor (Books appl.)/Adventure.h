#ifndef ADVENTURE_H
#define ADVENTURE_H

#include "Book.h"

class Adventure : public Book
{
public:
   Adventure(char *Author, char *Title, char *Language, int NumberPG, int BIN, char *Name_Of_Borrower)
      : Book(Author, Title, Language, NumberPG, BIN, "Adventure", Name_Of_Borrower)
   {
      DaysToBorrow = 20;
   }
};

#endif
