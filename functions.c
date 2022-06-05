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
    printf("--- Initialisation 1ere grille ---");

    Grid* current = malloc(sizeof(Grid));
   
    current->lignes = lignes;
    current->colonnes = colonnes;
    current->Tab = malloc(lignes * sizeof(int));

    for (int i=0; i < lignes ; i++) {
        current->Tab[i] = malloc(colonnes * sizeof(int));
    }
return current;
}

int random() {
   return 1 + rand() % 100;
}

Grid *Grid_fill(Grid* current) {
    int i, y;
        for (int i=0; i < current->lignes ; i++) {
            for (int y=0; i < current->colonnes ; y++) {
                current->Tab[i] = malloc(current->colonnes * sizeof(int));
            }
    }
    printf("tes quune merde | %d \n", current->Tab[i]);

return current;
}

Grid *Grid_display(Grid *current) {
}
