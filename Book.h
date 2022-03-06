#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED
#define BOOKFILENAME "books.bin"
///Structures declaration
typedef struct Book
{
    int code;
    char titre[50];
    char editeur[50];
    int annee;
} Book;
typedef struct BorrowCell
{
    Book book;
    struct BorrowCell *next;
} BorrowCell;
typedef BorrowCell* BorrowList;
///Functions
void newBook(Book *bk);
void saveLibrary(char *myfile,int n,BorrowList books);
Book seekBook(char *myfile,int code);
#endif // BOOK_H_INCLUDED
