#ifndef ABONNE_H_INCLUDED
#define ABONNE_H_INCLUDED
#include "Book.h"
///Structures declaration
typedef struct Subscriber
{
    int nums;
    char name[50];
    BorrowList borrowList;
} Subscriber;
typedef struct SubscriberCell
{
    Subscriber subscriber;
    struct SubscriberCell* next;
    struct SubscriberCell* last;
} SubscriberCell;
typedef SubscriberCell* SubscriberList;
///Functions
void newSubscriber(Subscriber *s);
SubscriberList addSubscriber(SubscriberList sl,Subscriber s);
SubscriberList seekSubscriber(SubscriberList sl,int num);
Subscriber addBook(Subscriber s,Book b);
void borrowBook(SubscriberList sl,int bkCode,int num);
void printSubscriber(Subscriber s );
void printSl(SubscriberList sl);
#endif // ABONNE_H_INCLUDED
