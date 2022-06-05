#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "struct.h"

int VerifInit(int,int);
Grid *Grid_init(int,int);
Grid *Grid_fill(Grid*);
Grid *Grid_display(Grid*);



#endif