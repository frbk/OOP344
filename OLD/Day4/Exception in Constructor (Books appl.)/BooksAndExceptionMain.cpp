#include <iostream>
#include "BookException.h"
#include "SciFiction.h"
#include "Fiction.h"
#include "Adventure.h"

#define MAX_BOOKS   10

void main()
{
   char YN = 'Y';
   char  Author[20], Title[40], Language[20], Borrower[30];
   int category, NumberPG, BIN;
   unsigned int count = 0;
   Book  *books[MAX_BOOKS];
   while (YN=='y' || YN=='Y')
   {
      cout << "Author: ";
      cin.getline(Author, sizeof(Author)-1, '\n');
      cout << "Title: ";
      cin.getline(Title, sizeof(Title)-1, '\n');
      cout << "Language: ";
      cin.getline(Language, sizeof(Language)-1, '\n');
      cout << "Name Of Borrower: ";
      cin.getline(Borrower, sizeof(Borrower)-1, '\n');
      cout << "Science Fiction=1, Adventure=2, Fiction=3 (1/2/3)? :";
      cin >> category;
      cout << "Number of pages: ";
      cin >> NumberPG;
      cout << "Book Id Number: ";
      cin >> BIN;
      try {
         switch(category)
         {
            case 1:
               books[count] = new SciFiction(Author, Title, Language, NumberPG, BIN, Borrower);
               break;
            case 2:
               books[count] = new Adventure(Author, Title, Language, NumberPG, BIN, Borrower);
               break;
            case 3:
               books[count] = new Fiction(Author, Title, Language, NumberPG, BIN, Borrower);
               break;
            default:
               throw BookException("Undefined Cathegory",-8);
               break;
         }
         count++;
         if (count==MAX_BOOKS)
         {
            /*
            For the Assignment replace the "break; with the requirements "
            */
            break;
         }
      }
      catch(BookException e)
      {
         cout << e.getCode() << ": " << e.getMessage() << endl;
      }
      cout << "Continue (Y/N)?: ";
      cin >> YN;
   }
  /*
  For the Assignment complete the code here."
  */
   int i;
   for (i=0 ; i<count ; i++)
   {
      books[i]->displayBorrowedBook();
   }
   for (i=0 ; i<count ; i++)
   {
      delete books[i];
   }
}
