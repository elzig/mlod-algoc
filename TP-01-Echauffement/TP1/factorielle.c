#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long TypeEntier;

TypeEntier factorielle(TypeEntier nombre)
{
    TypeEntier resultat = 1;
    for(int i=1; i<=nombre; i++)
    {
        resultat *= i;
    }
    return resultat;
}

int main()
{
    TypeEntier nombre;
    printf("Entrez le nombre à calculer : ");
    scanf("%llu", &nombre);
    TypeEntier nombre_factorielle = factorielle(nombre);
    printf("%llu! = %llu", nombre, nombre_factorielle);
    return 0;
}
