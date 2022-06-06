#include "functions.h"
#include "functions.c"
#include <stdlib.h>
#include <time.h>

/*		 GOL - ESIEE-IT Rémy JARDIN 		*/

int main() {
	srand(time(0));

	int lignes, colonnes, select, round;
	Grid* current;
	ControlGrid* ControlCurrent;

	printf("--- Game Of Life ---\n Colonnes: ");
	scanf("%d", &colonnes);

	printf("Lignes: ");
	scanf("%d", &lignes);

 	VerifInit(lignes, colonnes);
	current = Grid_init(lignes, colonnes);
	current = Grid_random(current);
	ControlCurrent = ControlGrid_init();
	ControlCurrent = ControlGrid_fill(ControlCurrent, current);
	round = round+1;


	printf("--- 1st Grid ---\n");
	Grid_display(ControlCurrent->last);

	while (1) {
        printf("--- %d grilles. ---\n1 - Génération suivante \n2 génération précédente", round);
        scanf("%d", &select);
        if (select==1) {
				printf("Generation %d \n", round);
                printf("============= \n");
                ControlCurrent=NextGrid(ControlCurrent, current);
                Grid_display(ControlCurrent->last);
                round+=1;
            }
            if (select == 2)
            {
                ControlCurrent= PreviousGrid(ControlCurrent->last);
                Grid_display(ControlCurrent->last);
                round-=1;
            }
            else {
                EXIT_FAILURE;
            }

        }

	return 0;
}
