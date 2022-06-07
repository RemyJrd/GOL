#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "struct.h"

ControlGrid* ControlGrid_init(void);
ControlGrid* ControlGrid_fill(ControlGrid*, Grid*);
ControlGrid* PreviousGrid(ControlGrid*);
ControlGrid* NextGrid(ControlGrid*,Grid*);
Grid* NeighbourCount(Grid*);
Grid* Generate(Grid*);
Grid* ReadGrille(Grid* g);
Grid* Grid_init(int,int);
Grid* Grid_random(Grid*);
int VerifInit(int,int);
void Grid_display(Grid*);
void save(Grid* g);
double random(void);


#endif