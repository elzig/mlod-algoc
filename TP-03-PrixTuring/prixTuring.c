/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring < turingWinners.txt > out.txt

 Tests
 diff out.txt turingWinners.txt

 Détection de fuites mémoires
 valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./prixTuring < turingWinners.txt > out.txt
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* This function scans a line of text (until \n) and returns a char* that contains all characters on the line (up to 255) excluding \n.
It also ensures the \0 termination.
**WARNING**: The result of this function has been allocated (calloc) by the function */
char* scanLine()
{
	int maxLineSize = 255;
	char c, *line = calloc(maxLineSize+1,sizeof(char));

	scanf("%250[^\n]", line);

	if ( (c = getchar()) != '\n') {
		/* we did not get all the line */
		line[250] = '[';
		line[251] = line[252] = line[253] = '.';
		line[254] = ']';
		// line[255] = '\0'; // useless because already initialized by calloc

		// let's skip all chars untli the end of line
		while (( (c = getchar()) != '\n') && c != EOF) ;
	}

	return line;
}

/* This function scans a line of text (until \n), converts it as an integer and returns this integer */
int scanLineAsInt() {
	int buf;
	scanf("%i\n",&buf);
	return buf;
}

typedef struct
{
	int annee;
	char* nom;
	char* description;
} Gagnant;

void readWinners(int nbGagnants)
{
	int c = 0;
	while(c<=nbGagnants)
	{
		// On lit les 3 lignes qui correspondent au gagnant
		Gagnant nobel;
		nobel.annee = scanLineAsInt();
		nobel.nom = scanLine();
		nobel.description = scanLine();
		
		// On stocke le gagnant dans un tableau
		

		// On désalloue la mémoire
		free(nobel.nom); nobel.nom = NULL;
		free(nobel.description); nobel.description = NULL;	
		c++;
	}
}

int main(void)
{

	int nbGagnants = scanLineAsInt();
	printf("nbGagnants = %i\n",nbGagnants);
	
	Gagnant* tabGagnants[] = readWinners(nbGagnants);
	printWinners();

	return EXIT_SUCCESS;
}
