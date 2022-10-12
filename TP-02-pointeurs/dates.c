#include <stdio.h>
#include <stdlib.h>
#include "dates.h"

void initialiseDate(Date* p)
{
    p->jour = 1;
    p->mois = Janvier;
    p->annee = 2000;
}

void afficheDate(Date* p)
{
    printf("%d %d %d", (*p).jour, (*p).mois, (*p).annee);
}

Date creerDateParCopie(void)
{
    Date d;
    initialiseDate(&d);
    return d;
}

Date* newDate(void)
{
    Date* pDate = (Date*)malloc(sizeof(Date));
    initialiseDate(pDate);
    return pDate;
}

int main(void)
{
    // Date d;

    // printf("Version 1 : initialisation d'une date allouée statiquement\n");
    // initialiseDate(&d);
    // afficheDate(&d);

    // printf("Version 2 : recopie d'une date allouée statiquement\n");
    // d = creerDateParCopie();
    // afficheDate(&d);

    printf("Version 3 : initialisation d'une date allouée dynamiquement\n");
    Date* pDate;
    pDate = newDate();
    afficheDate(pDate);
    free(pDate); pDate=NULL;
    
    return EXIT_SUCCESS;
}