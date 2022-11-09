// gcc -W -Wall -std=c99 DORE_mathieu-tpnote2.c -o DORE_mathieu-tpnote2
// ./DORE_mathieu-tpnote2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --------------------------------------------------
// Définition des types
// --------------------------------------------------

#define CHUNK_SIZE_MAX 5

typedef char* chunk;

struct cellule_s
{
	chunk val;
    int chunkSize;
	struct cellule_s* next;
};

typedef struct cellule_s Cellule;

typedef Cellule* String;


// --------------------------------------------------
// Implémentation des fonctions
// --------------------------------------------------

// fonction qui créée un nouveau string
String string_new_unique(chunk mot)
{
    int longueur = strlen(mot);
    String string = malloc(sizeof(Cellule));
    string->chunkSize = longueur;
    string->val = mot;
    string->next = NULL;
    
    return string;
}

String string_new(chunk mot)
{   
    // le chunk a une longueur max à ne pas dépasser
    int longueur = strlen(mot);
    String res;
    while(longueur>=CHUNK_SIZE_MAX)
    {
        char nouveau_mot[CHUNK_SIZE_MAX];
        for(int i=0; i<CHUNK_SIZE_MAX; i++)
        {
            nouveau_mot[i] = mot[i];
        }
        res->val = string_new_unique(nouveau_mot);
        // il manque le fait d'attribuer l'adresse dans next pour lier la chaîne
    }
}

// fonction qui retourne la taille du string (liste chaînée)
int string_length(String s)
{
    int res = 0;
    if(s == NULL)
    {
        return res;
    }

    else
    {   
        res += s->chunkSize;
        while(s->next != NULL)
        {
           res += s->chunkSize; 
        }
        return res;
    }
}

// fonctions d'affichage
void afficheElement(chunk mot)
{
	printf("%s ",mot);
}

void afficheString(String s) {
	String p = s;
	while(p != NULL){
		afficheElement(p->val);
		p = p->next;
	}
	printf("\n");
}

// fonction de destruction de la liste
void detruire(String s) {
	String suivant;
	String courant = s;
	while(courant != NULL){
		suivant = courant->next;
		free(courant);
		courant = suivant;
	}
}

// fonction d'insertion
String string_insert_at(String s, int pos, chunk new)
{
    String nouveau_string = string_new(new);

    for(int i=0; i<pos-1; i++)
    {
        String nouveau_string_vide = string_new("");
        s->next = nouveau_string_vide;
    }

    s->next = nouveau_string;

    return s;
}


// --------------------------------------------------
// Main
// --------------------------------------------------

int main(void)
{
    String s = string_new("HELLO !");
    afficheString(s);
    
    // test de la fonction string_length
    int size = string_length(s);
    printf("La taille du String est : %i\n", size);

    // test de la fonction string_inster_at
    s = string_insert_at(s, 7, "les pros du C");

    detruire(s);

    return EXIT_SUCCESS;
}