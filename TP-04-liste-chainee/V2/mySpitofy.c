// gcc -W -Wall -Wno-unused-parameter -std=c99 linkedList.c linkedListOfMusic.c mySpitofy.c -o mySpitofy
// ./mySpitofy

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include "linkedListOfMusic.h"


int main(void)
{
    char pathFichier[] = "music_test.csv";
    Liste listeMusique = NULL;
    lireFichierCSV(pathFichier, listeMusique);
    
    return EXIT_SUCCESS;
}