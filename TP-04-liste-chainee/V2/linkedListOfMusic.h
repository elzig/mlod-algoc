#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"

#define MAXCHAR 1000

// ----------------------------------------------------
// définition du type Musique
// ----------------------------------------------------
typedef struct
{
    char *name;
    char *artist;
    char *album;
    char *genre;
    char* discNumber;
    char* trackNumber;
    char* year;
} Music;

// ----------------------------------------------------
// fonctions extern de la bib linkedList.h
// ----------------------------------------------------
void afficheElement(Element e);
void detruireElement(Element e);
bool equalsElement(Element e1, Element e2);

// ----------------------------------------------------
// fonctions propres à la bib linkedListOfMusic.h
// ----------------------------------------------------