#pragma once

typedef enum
{
    Janvier = 1,
    Fevrier,
    Mars,
    Avril,
    Mai,
    Juin,
    Juillet,
    Aout,
    Septembre,
    Ocotbre,
    Novembre,
    Decembre
} Mois;

typedef struct
{
    int jour;
    Mois mois;
    int annee;
} Date;

int main(void);
void initialiseDate(Date *p);
Date creerDateParCopie(void);
