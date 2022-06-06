#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "struct.h"

int VerifInit(int,int);
Grid* Grid_init(int,int);
void Grid_display(Grid*);
ControlGrid* ControlGrid_init();
Grid* Grid_random(Grid*);
ControlGrid* ControlGrid_fill(ControlGrid*, Grid*);
double random(void);
Grid* NeighbourCount(Grid*);
Grid* Generate(Grid*);

#endif