#include "functions.h"
#include "functions.c"
#include <stdlib.h>
#include <time.h>

/*		 GOL - ESIEE-IT Rémy JARDIN 		*/

//TODO:
//AVANCER SUR CONTROLGRIDFILL, maintenant qu'on a calculer les voisins, il faut appliquer!

int main() {
	srand(time(0));

	int lignes, colonnes;
	Grid* current;
	//ControlGrid* ControlCurrent;

	printf("--- Game Of Life ---\n Colonnes: ");
	scanf("%d", &colonnes);

	printf("Lignes: ");
	scanf("%d", &lignes);

 	VerifInit(lignes, colonnes);
	current = Grid_init(lignes, colonnes);
	current = Grid_random(current);
	current = Grid_display(current);


	return 0;
}
