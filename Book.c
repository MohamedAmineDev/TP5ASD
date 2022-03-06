#include <stdio.h>
#include <stdlib.h>
#include "Book.h"
///Fonction
void newBook(Book *bk)
{
    printf("Donner le code du livre\n");
    scanf("%d",&bk->code);
    fflush(stdin);
    printf("Donner le titre de l'auteur\n");
    gets(bk->titre);
    printf("Donner l'editeur\n");
    gets(bk->editeur);
    printf("Donner l'annee de l'edition\n");
    scanf("%d",&bk->annee);
}
void saveLibrary(char *myfile,int n,BorrowList books)
{
    int i=0;
    if(i<n)
    {
        FILE *fichier=NULL;
        fichier=fopen(myfile,"wb");
        BorrowCell *actuel=NULL;
        actuel=books;
        do
        {
            fwrite(actuel,sizeof(Book),1,fichier);
            actuel=actuel->next;
            i++;
        }
        while(i<n);
        fclose(fichier);
    }
    else
    {
        printf("On ne peut pas sauvegarder %d livres !",n);
    }

}

Book seekBook(char *myfile,int code)
{
    FILE *fichier=NULL;
    fichier=fopen(myfile,"rb");
    Book b;
    while(fread(&b,sizeof(Book),1,fichier))
    {
        if(b.code=code)
        {
            return b;
        }
    }
    b.code=-1;
    return b;
}

