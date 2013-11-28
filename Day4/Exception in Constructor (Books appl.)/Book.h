#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <iomanip>
#include "BookException.h"

class Book
{
   string Author, Title, Language, BookCategory, Name_Of_Borrower;
   unsigned int NumPages, bookIdentNum;
protected:
   unsigned short DaysToBorrow;
   Book(char *Author, char *Title, char *Language, int NumberPG, int BIN, char *BookCategory, char *Name_Of_Borrower)
   {
      if (!Author || !strlen(Author))
         throw BookException("Author is undefined", -1);
      if (!Title || !strlen(Title))
         throw BookException("Title is undefined", -2);
      if(!Language || !strlen(Language))
         throw BookException("Language is undefined", -3);
      if (NumberPG<=0)
         throw BookException("Incorrect number of pager", -4);
      if (BIN<=0)
         throw BookException("Incorrect Book Identification Number", -5);
      if (!BookCategory || !strlen(BookCategory))
         throw BookException("Book category is undefined", -6);
      if (!Name_Of_Borrower || !strlen(Name_Of_Borrower))
         throw BookException("Name Of Borrower is undefined", -7);

      this->Author = Author;
      this->Title = Title;
      this->Language = Language;
      this->BookCategory = BookCategory;
      this->Name_Of_Borrower = Name_Of_Borrower;
      NumPages = NumberPG;
      bookIdentNum = BIN;
   }
public:
   unsigned short getDaysToBorrow() {return DaysToBorrow; }
   void displayBorrowedBook()
   {
      cout << setfill('=') << setw(40) << ' ' << endl;
      cout.fill('.');
      cout.setf(ios::left);
      cout << setw(30) << "Author" << Author << endl;
      cout << setw(30) << "Title" << Title << endl;
      cout << setw(30) << "Language" << Language << endl;
      cout << setw(30) << "Category" << BookCategory << endl;
      cout << setw(30) << "Number of pages" << NumPages << endl;
      cout << setw(30) << "BIN" << bookIdentNum << endl;
      cout << setw(30) << "Name of borrower" << Name_Of_Borrower << endl;
      cout << setw(30) << "Days to borrow" << DaysToBorrow << endl;
      cout.fill(' ');
      cout.unsetf(ios::left);
   }
};

#endif
