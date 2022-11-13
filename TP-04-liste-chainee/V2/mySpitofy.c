#include "linkedListOfMusic.h"
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    char* pathFichier = "music.csv";
    Liste listeMusique = NULL;
    FILE* fichier = fopen(pathFichier, "r");
    
    // gestion des erreurs d'ouverture du fichier
    if((fichier == NULL))
    {
        printf ("Code de l'erreur : %d\n", errno);

        if(errno == ENOENT)
        {
            printf("Le fichier n'existe pas !\n");
            return EXIT_FAILURE;
        }
        else
        {
            printf("Erreur inconnue\n");
            return EXIT_FAILURE;
        }
    }

    listeMusique = CSVVersListe(fichier, listeMusique);
    // triABulles(listeMusique);
    afficheListe_i(listeMusique);
    
    fclose(fichier);
    detruire_i(listeMusique);
    

    return EXIT_SUCCESS;
}
