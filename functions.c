#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <time.h>

int VerifInit(int lignes, int colonnes) {
    if (lignes <= 0 && colonnes <= 0) {
        printf("Erreur de saisie !");
        return EXIT_FAILURE;
    }
        return 0;
}

void Grilles_init() {
    printf("Démarrage ! \n");
    calloc();
}