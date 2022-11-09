// gcc -W -Wall -Wno-unused-parameter -std=c99 linkedList.c linkedListOfMusic.c mySpitofy.c -o mySpitofy
// ./mySpitofy

#include <errno.h>
#include "linkedListOfMusic.h"


int main(void)
{
    // Ouverture du fichier
    // char fileName[] = "music.csv";
    // FILE* f;

    // f = fopen(fileName, 'r');

    // if((f == NULL))
    // {
    //     printf ("Code de l'erreur : %d\n", errno);

    //     if(errno == ENOENT)
    //     {
    //         printf("Le fichier n'existe pas !\n");
    //     }
    //     else
    //     {
    //         printf("Erreur inconnue\n");
    //     }

    //     return EXIT_FAILURE;
    // }

    // char buffer[255];
    // while(fgets(buffer, 10, f) != NULL)
    // {
    //     printf(" %s",buffer);
    // }

    // fclose(f);

    // test d'affichage d'une liste d'une musique
    Music musique;
    Liste l = NULL;

    musique.name = "En Y";
    musique.artist = "Jul";
    musique.album = "My World";
    musique.genre = "Rap";
    musique.discNumber = "unknown";
    musique.track = 1;
    musique.number = 1;
    musique.year = 2015;

    l = creer(&musique);
    afficheListe_r(l);

    // detruire_r(l);

    return EXIT_SUCCESS;
}