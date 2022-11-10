#include "linkedListOfMusic.h"
#include <string.h>
#include <stdio.h>
#include <errno.h>


// ----------------------------------------------------
// fonctions extern de la bib linkedList.h
// ----------------------------------------------------

void afficheElement(Element e)
{
    printf("%s,", ((Music *)e)->name);
    printf("%s,", ((Music *)e)->artist);
    printf("%s,", ((Music *)e)->album);
    printf("%s,", ((Music *)e)->genre);
    printf("%s,", ((Music *)e)->discNumber);
    printf("%s,", ((Music *)e)->trackNumber);
    printf("%s", ((Music *)e)->year);
}


void detruireElement(Element e)
{
    free((Music *)e);
}


bool equalsElement(Element e1, Element e2)
{
	return !memcmp(e1, e2, sizeof(Music));
}


// ----------------------------------------------------
// fonctions propres à la bib linkedListOfMusic.h
// ----------------------------------------------------

Music creerMusique(char *name1, char *artist1, char *album1, char *genre1, char* discNumber1, char* trackNumber1, char* year1)
{
    Music* music = malloc(sizeof(Music));
    music->name = name1;
    music->artist = artist1;
    music->album = album1;
    music->genre = genre1;
    music->discNumber = discNumber1;
    music->trackNumber = trackNumber1;
    music->year = year1;

    return *music;
}

Music* ligneVersMusique(char* ligne)
{
    Music *music = malloc(sizeof(Music));

    // récupération des infos séparés par la virgule
    music->name = strsep(&ligne, ",");
    music->artist = strsep(&ligne, ",");
    music->album = strsep(&ligne, ",");
    music->genre = strsep(&ligne, ",");
    music->discNumber = strsep(&ligne, ",");
    music->trackNumber = strsep(&ligne, ",");
    music->year = strsep(&ligne, ",");

    return music;
}


void lireFichierCSV(char* pathFichier, Liste listeMusique)
{
    // ouverture du fichier
    char nomFichier[] = "music_test.csv";
    FILE* fichier;

    fichier = fopen(nomFichier, "r");

    // gestion des erreurs d'ouverture
    if((fichier == NULL))
    {
        printf ("Code de l'erreur : %d\n", errno);

        if(errno == ENOENT)
        {
            printf("Le fichier n'existe pas !\n");
        }
        else
        {
            printf("Erreur inconnue\n");
        }

        return ;
    }

    // lecture des lignes
    char ligne[MAXCHAR];
    int nb_musique = 0;
    Music* musique;
    while(fgets(ligne, MAXCHAR, fichier) != NULL)
    {
        char* lignedup = strdup(ligne);
        musique = ligneVersMusique(lignedup);
        listeMusique = ajoutFin_r(musique, listeMusique);
        free(musique);
        free(lignedup);

        /*nb_musique ++;
        char* ligne_p = ligne;

        char* name = strsep(&ligne_p, ",");
        char* artist = strsep(&ligne_p, ",");
        char* album = strsep(&ligne_p, ",");
        char* genre = strsep(&ligne_p, ",");
        char* discNumber = strsep(&ligne_p, ",");
        char* trackNumber = strsep(&ligne_p, ",");
        char* year = strsep(&ligne_p, ",");
        Music musique = creerMusique(name, artist, album, genre, discNumber, trackNumber, year);
        // afficheElement(&musique);
        listeMusique = ajoutTete(&musique, listeMusique);
        afficheListe_i(listeMusique);*/
    }
    // printf("Nombre de musiques : %i\n", nb_musique);
    // rewind(fichier);
    // size_t len;

    // for(int i = 0; i < nb_musique; i++)
    // {
    //     fgets(ligne, MAXCHAR, fichier);
    //     ligne[(len = strcspn(ligne, "\n"))] = 0;

    //     if(i==0)
    //     {
    //         continue;
    //     }

    //     char* ligne_p = strdup(ligne);

    //     char* name = strsep(&ligne_p, ",");
    //     char* artist = strsep(&ligne_p, ",");
    //     char* album = strsep(&ligne_p, ",");
    //     char* genre = strsep(&ligne_p, ",");
    //     char* discNumber = strsep(&ligne_p, ",");
    //     char* trackNumber = strsep(&ligne_p, ",");
    //     char* year = strsep(&ligne_p, ",");
    //     Music musique = creerMusique(name, artist, album, genre, discNumber, trackNumber, year);
    //     listeMusique = ajoutFin_r(&musique, listeMusique);
    // }

    afficheListe_r(listeMusique);

    fclose(fichier);
}

