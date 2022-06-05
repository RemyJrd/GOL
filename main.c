#include "functions.h"
#include "functions.c"
#include <time.h>

/*		 GOL - ESIEE-IT Rémy JARDIN 		*/

int main() {
	srand(time(0));

	int lignes, colonnes;
	Grid* current;

	printf("--- Game Of Life ---\n Colonnes: ");
	scanf("%d", &colonnes);

	printf("Lignes: ");
	scanf("%d", &lignes);


	current = VerifInit(lignes, colonnes);
	current = Grid_init(lignes, colonnes);
	current = Grid_fill(current);



	return 0;
}
