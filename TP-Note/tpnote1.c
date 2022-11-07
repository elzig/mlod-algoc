// tpnote1.c

#include <stdio.h>

int* repeat(int* t1, int* t2){
    int taille_t1 = (int)(sizeof(t1)/sizeof(t1[0]));
    int taille_resultat = 0;
    for(int i=0; i<taille_t1; i++){
        taille_resultat += t1[i];
    }
    int resultat[taille_resultat];
    for(int i=0; i<taille_t1; i++){
        for(int j; j<t1[i]; j++){
            resultat[j] = t1[i]*t2[i];
        }
    }
    return resultat;
}

int main(void){
    int t1[3] = {1, 2, 4};
    int t2[3] = {10, 3, 8};
    int* resultat;
    resultat = repeat(t1, t2);
    int taille_resultat = (int)(sizeof(resultat)/sizeof(resultat[0]));
    // L'IMPRESSION NE FONCTIONNE PAS
    //for(int i=0; i<taille_resultat; i++){
    //    printf("%i/n",resultat[i]);
    //}
    return 0;
}