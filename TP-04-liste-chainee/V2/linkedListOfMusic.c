#include "linkedListOfMusic.h"


// fonctions extern de la bib linkedList.h
void afficheElement(Element e)
{
    printf("%s,", ((Music *)e)->name);
    printf("%s,", ((Music *)e)->artist);
    printf("%s,", ((Music *)e)->album);
    printf("%s,", ((Music *)e)->genre);
    printf("%s,", ((Music *)e)->discNumber);
    printf("%i,", ((Music *)e)->track);
    printf("%i,", ((Music *)e)->number);
    printf("%i", ((Music *)e)->year);
}


void detruireElement(Element e)
{
    free((Music *)e);
}


bool equalsElement(Element e1, Element e2)
{
	return !memcmp(e1, e2, sizeof(Music));
}