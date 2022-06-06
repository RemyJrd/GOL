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

ControlGrid *ControlGrid_init() {
    printf("--- Initialisation ControlGrid ---\n");

    ControlGrid* controlcurrent = malloc(sizeof(*controlcurrent));
    if(controlcurrent != NULL)
    {controlcurrent->first = NULL;
    controlcurrent->last = NULL;}
    
return controlcurrent;
}

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

ControlGrid* ControlGrid_fill(ControlGrid* controlcurrent, Grid* current) {
        if (controlcurrent != NULL) {
            
        Grid* nouvelle = malloc(sizeof *nouvelle);
        nouvelle = Grid_init(current->lignes,current->colonnes);
        if (nouvelle != NULL) {   
            for(int i = 0; i < current->lignes; i++) {
                for(int y = 0; y < current->colonnes; y++) {
                    nouvelle->Tab[i][y] = current->Tab[i][y];
                }
            }
            nouvelle->next = NULL;
            if (controlcurrent->last == NULL) {
                nouvelle->previous = NULL;
                controlcurrent->first = nouvelle;
                controlcurrent->last = nouvelle;
                printf("prout");
            }
            else
            {
                controlcurrent->last->next = nouvelle;
                nouvelle->previous = controlcurrent->last;
                controlcurrent->last = nouvelle;
            }
        }
    }

return controlcurrent;
 }

double random() {
   return 0 + (int) (rand() / (double) (RAND_MAX + 1) * (1 - 0 + 1));
}

void Grid_display(Grid *current) {
    printf("--- Affichage de la Grille ! ---- \n");
    int i, y;
        for (i=0; i < current->lignes ; i++) {
            for (y=0; y < current->colonnes ; y++) {
                printf("| %d |", current->Tab[i][y]);
            }
            printf("\n");
    }
}

Grid* NeighbourCount(Grid* current) {
    int i, y, cnt=0;
    Grid* Nei = Grid_init(current->lignes, current->colonnes);
    for(i=0; i<current->lignes; i++) {
        for(y=0; y<current->colonnes; y++) {
                    if (i < current->lignes-1)

                    if (current->Tab[i+1][y] == 1)
                    {
                        cnt++;
                    }
                    if (i>0)
                    {
                        if (current->Tab[i-1][y] == 1)
                        {
                            cnt++;
                        }
                    }
                    if (y>0)
                    {
                    if (i < current->lignes-1)
                        if (current->Tab[i+1][y-1]==1)
                        {
                            cnt++;
                        }
                    }
                    if (y>0)
                    {
                        if (current->Tab[i][y-1]==1)
                        {
                            cnt++;
                        }
                    }
                    if (y>0 && i>0)
                    {
                        if (current->Tab[i-1][y-1] == 1)
                        {
                            cnt++;
                        }
                    }
                    if (y < current->colonnes-1 && i< current->lignes-1)
                    if (current->Tab [i+1][y+1]== 1)
                    {
                        cnt++;
                    }
                    if (y < current->colonnes-1)
                    if (current->Tab[i][y+1]==1)
                    {
                        cnt++;
                    }
                    if (i>0)
                    {
                        if (y < current->colonnes-1)
                        if (current->Tab[i-1][y+1]== 1)
                        {
                            cnt++;
                        }
        }
        Nei->Tab[i][y]=cnt;
        cnt=0;
       
            }
             
}

    return(Nei);
}

Grid* Generate(Grid* current) {
    Grid* nouvelle=NeighbourCount(current);
    int i, y;
    for (i = 0 ; i < current->lignes ; i++) {
        for (y = 0 ; y < current->colonnes ; y++) {
            if (current->Tab[i][y] == 1) 
            {
                if (nouvelle->Tab[i][y] == 2 || nouvelle->Tab[i][y] == 3) {
                    printf("sheeesh");
                    current->Tab[i][y] = 1;}
                if (nouvelle->Tab[i][y] >= 4 && nouvelle->Tab[i][y] <= 8) {
                    printf("pute");
                    current->Tab[i][y] = 0;}
                if (nouvelle->Tab[i][y] == 0 || nouvelle->Tab[i][y] == 1) {
                    printf("dedicace a personne");
                    current->Tab[i][y] = 0;}
            }
            else
            {
                if (nouvelle->Tab[i][y] == 3)
                {
                    current->Tab[i][y] = 1;
                }
            }
        }
    }
    return current;
}

ControlGrid* PreviousGrid(ControlGrid *controlcurrent){
    Grid* current = controlcurrent->last;

    current = current->previous;
    controlcurrent->last = current;

    return controlcurrent;
}

ControlGrid* NextGrid(ControlGrid *controlcurrent, Grid* g){
    Grid* current = controlcurrent->last;
    
    current = current->next;
if (controlcurrent->last->next == NULL)
    {
        g =  Generate(g);
        controlcurrent = ControlGrid_fill(controlcurrent,g);
        
        return controlcurrent;
    }
else {
    printf("test2");
    controlcurrent->last = current;
    return controlcurrent;
}
}
//sheesh vérifie l'initiation à null.