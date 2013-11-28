#ifndef FICTION_H
#define FICTION_H

#include "Book.h"

class Fiction : public Book
{
public:
   Fiction(char *Author, char *Title, char *Language, int NumberPG, int BIN, char *Name_Of_Borrower)
      : Book(Author, Title, Language, NumberPG, BIN, "Fiction", Name_Of_Borrower)
   {
      DaysToBorrow = 25;
   }
};

#endif
