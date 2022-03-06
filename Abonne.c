#include <stdio.h>
#include <stdlib.h>
#include "Abonne.h"
#include <string.h>
///Fonction
void newSubscriber(Subscriber *s)
{
    printf("Donner le numero de l'inscription\n");
    scanf("%d",&s->nums);
    fflush(stdin);
    printf("Donner le nom de l'abonne\n");
    gets(s->name);
    s->borrowList=NULL;
}
SubscriberList addSubscriber(SubscriberList sl,Subscriber s)
{
    SubscriberCell *newCell=NULL;
    newCell=malloc(sizeof(SubscriberCell));
    newCell->subscriber.nums=s.nums;
    strcpy(newCell->subscriber.name,s.name);
    if(sl==NULL)
    {
        newCell->next=NULL;
        newCell->last=NULL;
        sl=newCell;
        return sl;
    }
    else
    {
        SubscriberCell *actuel=NULL;
        SubscriberCell *last=NULL;
        actuel=sl;
        while(actuel!=NULL)
        {
            if(s.nums<actuel->subscriber.nums)
            {
                newCell->next=actuel;
                newCell->last=actuel->last;
                actuel->last=newCell;
                return sl;
            }
            last=actuel;
            actuel=actuel->next;
        }
        last->next=newCell;
        newCell->next=NULL;
        newCell->last=last;
        return sl;
    }
}
SubscriberList seekSubscriber(SubscriberList sl,int num)
{
    if(sl==NULL)
    {
        return NULL;
    }
    else
    {
        SubscriberCell *actuel=NULL;
        actuel=sl;
        while(actuel!=NULL)
        {
            if(actuel->subscriber.nums==num)
            {
                return actuel;
            }
            actuel=actuel->next;
        }
        return NULL;
    }
}

Subscriber addBook(Subscriber s,Book b)
{
    BorrowCell *newBook=NULL;
    newBook=malloc(sizeof(BorrowCell));
    newBook->book.code=b.code;
    strcpy(newBook->book.titre,b.titre);
    strcpy(newBook->book.editeur,b.editeur);
    newBook->book.annee=b.annee;
    if(s.borrowList==NULL)
    {
        s.borrowList=newBook;
        newBook->next=NULL;
        return s;
    }
    else
    {
        BorrowCell *actual=NULL;
        actual=s.borrowList;
        while(actual->next!=NULL)
        {
            actual=actual->next;
        }
        actual->next=newBook;
        return s;
    }
}
void borrowBook(SubscriberList sl,int bkCode,int num)
{
    SubscriberCell *actual=NULL;
    actual=seekSubscriber(sl,num);
    if(actual!=NULL)
    {
        Book b=seekBook(BOOKFILENAME,bkCode);
        if(b.code!=-1)
        {
            actual->subscriber=addBook(actual->subscriber,b);
            printf("L'emprunt est un succees !\n");
        }
        else
        {
            printf("Livre introuvable !\n");
        }
    }
    else
    {
        printf("Liste d'abonne est vide !\n");
    }
}
void printSubscriber(Subscriber s )
{
    printf("Numero abonne : %d\n",s.nums);
    printf("Nom : %s\n",s.name);
    if(s.borrowList!=NULL)
    {
        printf("La liste des livres empruntees :\n");
        BorrowCell *actuel=NULL;
        actuel=s.borrowList;
        while(actuel!=NULL)
        {
            printf("Code : %d\n",actuel->book.code);
            printf("Titre : %s\n",actuel->book.titre);
            printf("Editeur : %s\n",actuel->book.editeur);
            printf("Annee  : %d\n",actuel->book.annee);
            actuel=actuel->next;
        }
    }
    else
    {
        printf("La liste des livres empruntees est vide !\n");
    }
}
void printSl(SubscriberList sl)
{
    if(!sl==NULL)
    {
        printSubscriber(sl->subscriber);
        printSl(sl->last);
    }
}
