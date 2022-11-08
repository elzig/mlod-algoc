#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void afficheElement(Element e)
{
    printf("%s ", (char*)e);
}


void detruireElement(Element e)
{}


bool equalsElement(Element e1, Element e2)
{
    return(strcmp((char*)e1, (char*)e2)==0);
}


int main(void)
{
    Liste l = NULL, p;
    printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");

    l = ajoutTete("!",l);
    l = ajoutTete("Mathieu",l);
    l = ajoutTete("suis",l);
    l = ajoutTete("je",l);
    l = ajoutTete("Bonjour",l);

    afficheListe_i(l);

    p = cherche_r("je",l);
	printf("cherche_r('je') : %s\n",estVide(p)?"[ERREUR] pas trouve":"trouve !!!");

    printf("retirePremier_r('Mathieu')  : ");
	l = retirePremier_r("Mathieu",l);
	afficheListe_r(l);

    detruire_r(l);

    return EXIT_SUCCESS;
}