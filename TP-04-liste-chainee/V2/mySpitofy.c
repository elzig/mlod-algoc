// gcc -W -Wall -Wno-unused-parameter -std=c99 linkedListOfMusic.c mySpitofy.c -o mySpitofy
// ./mySpitofy

#include "linkedListOfMusic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *name;
    char *artist;
    char *album;
    char *genre;
    char *discNumber;
    int track;
    int number;
    int year;
} Musique;


// définition des fonctions extern
void afficheElement(Element e)
{
    printf("%s,", ((Musique *)e)->name);
    printf("%s,", ((Musique *)e)->artist);
    printf("%s,", ((Musique *)e)->album);
    printf("%s,", ((Musique *)e)->genre);
    printf("%s,", ((Musique *)e)->discNumber);
    printf("%i,", ((Musique *)e)->track);
    printf("%i,", ((Musique *)e)->number);
    printf("%i,", ((Musique *)e)->year);
}


void detruireElement(Element e)
{
    free((Musique *)e);
}


bool equalsElement(Element e1, Element e2)
{

}


int main(void)
{
    // Ouverture du fichier

    return EXIT_SUCCESS;
}