#include "liste-chainee.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
	Liste liste = malloc(sizeof(Cellule));
	liste->val = v;
	liste->suiv = NULL;
	return liste;
}

// retourne la taille de la liste
int taille(Liste l){
	return sizeof(l)/sizeof(l[0]);
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
	Cellule* nouvelle_cellule_p = malloc(sizeof(Cellule*));
	nouvelle_cellule_p->val = v;
	nouvelle_cellule_p->suiv = l;
	l = nouvelle_cellule_p;
	return l;
}


void afficheElement(Element e) {
	printf("%i ",e);
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe afficheElement
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	if(estVide(l) == true){
		printf("La liste est vide\n");
	}
	else{
		Cellule* cellule_courante_p = l;
		while(cellule_courante_p != NULL){
			afficheElement(cellule_courante_p->val);
			cellule_courante_p = cellule_courante_p->suiv;
		}
	}
}

// version recursive
void afficheListe_r(Liste l) {
	if(estVide(l) == true){
		printf("Fin de la liste\n");
	}
	else{
		afficheElement(l->val);
		afficheListe_r(l->suiv);
	}
}

void detruireElement(Element e) {
	;
}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	TODO;
}

// version récursive
void detruire_r(Liste l) {
	TODO;
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	Cellule* cellule_courante_p = l;
	Cellule* derniere_cellule_p = malloc(sizeof(Cellule*));
	derniere_cellule_p->val = v;
	derniere_cellule_p->suiv = NULL;
	while(cellule_courante_p->suiv != NULL){
		cellule_courante_p->suiv = derniere_cellule_p;
	}
	return l;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	if(estVide(l)){
		l = creer(v);
	}
	else{
		l->suiv = ajoutFin_r(v, l->suiv);
	}
	return l;
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
	return e1 == e2;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	return TODO;
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	return TODO;
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	return TODO;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	return TODO;
}


void afficheEnvers_r(Liste l) {
	TODO;
}



