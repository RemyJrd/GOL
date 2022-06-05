#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "struct.h"

int VerifInit(int lignes, int colonnes) {
    if (lignes <= 0 && colonnes <= 0) {
        printf("Erreur de saisie !");
        return EXIT_FAILURE;
    }
        return 0;
}

Grid *Grid_init(int lignes, int colonnes) {
    int i;
    printf("--- Initialisation 1ere grille --- \n");
    Grid* current = (Grid*) malloc(sizeof(Grid));
    current->lignes = lignes;
    current->colonnes = colonnes;
    current->Tab = malloc(lignes * sizeof(int*));

    for (i=0; i < lignes ; i++) {
        current->Tab[i] = malloc(colonnes * sizeof(int));
    }
return (current);
}

/* ControlGrid *ControlGrid_init() {
    printf("--- Initialisation ControlGrid ---");

    ControlGrid* controlcurrent = malloc(sizeof(ControlGrid));
    controlcurrent->First = NULL;
    controlcurrent->Last = NULL;
return controlcurrent;
} */

Grid* Grid_random(Grid* current) {
    int i, y;
    printf("--- Process en cours... --- \n");
        for (i=0; i < current->lignes; i++) {
            for (y=0; y < current->colonnes; y++) {
                current->Tab[i][y] = random();
            }
    }
return current;
}

/* ControlGrid* ControlGrid_fill(ControlGrid* controlcurrent, Grid* current) {
    printf("--- Remplissage ControlGrid ---");

    if (controlcurrent->First == NULL) {
        Grid* nouvelle = malloc(sizeof(*nouvelle));
        nouvelle= Grid_fill(nouvelle);
    }
    else {

    }
   
return controlcurrent;
} */

double random() {
   return 0 + (int) (rand() / (double) (RAND_MAX + 1) * (1 - 0 + 1));
}

Grid *Grid_display(Grid *current) {
    printf("--- Affichage de la Grille ! ---- \n");
    int i, y;
        for (i=0; i < current->lignes ; i++) {
            for (y=0; y < current->colonnes ; y++) {
                printf("| %d |", current->Tab[i][y]);
            }
            printf("\n");
    }

return current;
}
