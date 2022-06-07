#include "functions.h"
#include "functions.c"
#include <stdlib.h>
#include <time.h>

/*		 GOL - ESIEE-IT Rémy JARDIN 		*/

int main() {
	srand(time(0));

	int lignes, colonnes, select, round, choixmode;
	Grid* current;
	ControlGrid* ControlCurrent;

	printf("--- Game Of Life ---\nChoisir le type de lancement: \n1 - Lignes et colonnes manuelle\n2 - Grille predefini\n");
	scanf("%d", &choixmode);
	
	
	if (choixmode == 1) {
		printf("Nombres de lignes : ");
		scanf("%d", &lignes);

		printf("Nombres de colonnes: ");
		scanf("%d", &colonnes);

 		VerifInit(lignes, colonnes);
		current = Grid_init(lignes, colonnes);
		current = Grid_random(current);
		ControlCurrent = ControlGrid_init();
		ControlCurrent = ControlGrid_fill(ControlCurrent, current);
		round = 1;

		printf("--- 1ere grille ---\n");
		Grid_display(ControlCurrent->last);

		while (1) {
        	printf("--- %d grilles. ---\n1 - Generation suivante \n2 Generation precedente\n", round);
        	scanf("%d", &select);
        	if (select==1) {
				printf("Generation %d \n", round);
                ControlCurrent=NextGrid(ControlCurrent, current);
                round = round+1;
            }
            if (select == 2)
            {
                ControlCurrent= PreviousGrid(ControlCurrent);
                round = round-1;
            }
            else {
                EXIT_FAILURE;
            }
		Grid_display(ControlCurrent->last);
        }
	}
	else if (choixmode==2) {
        printf("Veuillez entrer la taille de la grille a generer : \n Lignes: ");
        scanf("%d", &lignes);
		printf("Colonnes: ");
		scanf("%d", &colonnes);
		current = Grid_init(lignes,colonnes);
		current = Grid_random(current);
		current = ReadGrille(current);
		int nombregen;
        printf("Combien de generations voulez-vous generer ? : ");
        scanf("%d", &nombregen);
        int gen=0;
        while (gen < nombregen)
        {
            Generate(current);
            gen++;
        }
        printf("Vous trouverez dans un fichier write.txt le resultat de la partie");
        save(current);
	} 
	else {
		printf("Erreur de saisie !");
	}

return 0;
}
