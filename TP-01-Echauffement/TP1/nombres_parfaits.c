#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    printf("Entrez la valeur de N : ");
    scanf("%d", &N);
    if(N<=0)
    {
        printf("Le nombre n'est pas strictement positif");
    }
    else
    {
        int comp=0;
        for(int i=1; i<N; i++)
        {
            if(N%i==0)
            {
                comp += i;
            }
        }
        if(comp==N)
        {
            printf("%d est un nombre parfait", N);
        }
        else
        {
            printf("%d n'est pas un nombre parfait", N);
        }       
    }
    return EXIT_SUCCESS;
}