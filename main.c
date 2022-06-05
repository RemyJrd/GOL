#include "functions.h"
#include "functions.c"
#include <time.h>

/*		 GOL - ESIEE-IT Rémy JARDIN 		*/

int main() {
	srand(time(0));
	
	int lignes, colonnes;

	printf("--- Game Of Life ---\n Colonnes: ");
	scanf("%d", &colonnes);

	printf("Lignes: ");
	scanf("%d", &lignes);

	VerifInit(lignes, colonnes);
	Grid_init(lignes, colonnes);


	return 0;
}
