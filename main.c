#include "functions.h"
#include "functions.c"

/*		 GOL - ESIEE-IT Rémy JARDIN 		*/

int main() {
	int colonnes, lignes;

	printf("--- Game Of Life ---\n Colonnes: ");
	scanf("%d", &colonnes);

	printf("Lignes: ");
	scanf("%d", &lignes);

	VerifInit(lignes, colonnes);

	return 0;
}
