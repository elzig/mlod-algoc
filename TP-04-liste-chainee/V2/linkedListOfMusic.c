#include "linkedListOfMusic.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


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
    Music* musique = (Music*)e;
    free(musique);
}


bool equalsElement(Element e1, Element e2)
{
	return !memcmp(e1, e2, sizeof(Music));
}


// ----------------------------------------------------
// fonctions propres à la bib linkedListOfMusic.h
// ----------------------------------------------------

Music* ligneVersMusique(char* ligne){
    Music* musique = malloc(sizeof(Music));
    char *mot, *ligne_dup = strdup(ligne); // on duplique la ligne car on va réallouer le pointeur
    
    // on sépare les mots de la ligne 1 à 1 puis on les assigne
    mot = strsep(&ligne_dup, ",");
    musique->name = calloc(sizeof(char), strlen(mot)+1);
    strcpy(musique->name, mot);

    mot = strsep(&ligne_dup, ",");
    musique->artist = calloc(sizeof(char), strlen(mot)+1);
    strcpy(musique->artist, mot);

    mot = strsep(&ligne_dup, ",");
    musique->album = calloc(sizeof(char), strlen(mot)+1);
    strcpy(musique->album, mot);

    mot = strsep(&ligne_dup, ",");
    musique->genre = calloc(sizeof(char), strlen(mot)+1);
    strcpy(musique->genre, mot);

    mot = strsep(&ligne_dup, ",");
    musique->discNumber = calloc(sizeof(char), strlen(mot)+1);
    strcpy(musique->discNumber, mot);

    mot = strsep(&ligne_dup, ",");
    musique->trackNumber = calloc(sizeof(char), strlen(mot)+1);
    strcpy(musique->trackNumber, mot);

    mot = strsep(&ligne_dup, ",");
    musique->year = calloc(sizeof(char), strlen(mot)+1);
    strcpy(musique->year, mot);
    
    return musique;
}


Liste CSVVersListe(FILE* fichier, Liste listeMusique)
{
    // on fait un calloc pour la ligne afin d'éviter les problèmes de mémoire
    // pour ne pas remplacer les anciennes cellules déjà créées
    char* ligne = calloc(MAXCHAR, sizeof(char));
    fgets(ligne, MAXCHAR, fichier);
    
    // on crée une liste avec la première ligne (Name, Artist, ...)
    listeMusique = creer(ligneVersMusique(ligne));
    free(ligne);

    while(true)
    {
        ligne = calloc(MAXCHAR, sizeof(char));
        fgets(ligne, MAXCHAR, fichier);

        // on sort de la boucle quand on rencontre une ligne vide
        if(strlen(ligne) == 0)
        {
            free(ligne);
            break;
        }

        // on utilise ajoutFin_i sinon la liste sera à l'envers
        listeMusique = ajoutFin_i(ligneVersMusique(ligne), listeMusique);
        free(ligne);
    }
    
    return listeMusique;
}


Liste triABulles(Liste listeMusique){
	// pour éviter les erreurs de segmentation avec les ->
    if(estVide(listeMusique)){
        return NULL;
    }

    Liste precedent = listeMusique;
    Liste suivant = NULL;

    //on parcourt la liste une première fois
    while(!estVide(precedent)){
        suivant = precedent->suiv;

        // on permute les éléments 2 à 2 à chaque fois si le suivant est plus petit
        while(!estVide(suivant))
        {
            if(atoi(((Music*)(suivant->val))->year) < atoi(((Music*)(precedent->val))->year))
            {
                // permutation des éléments
                void* tmp;
                tmp = suivant->val;
                suivant->val = precedent->val;
                precedent->val = tmp;
            }
            suivant = suivant->suiv;
        }
        precedent = precedent->suiv;
    }
    return listeMusique;
}