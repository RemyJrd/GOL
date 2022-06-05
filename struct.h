#ifndef STRUCT_H
#define STRUCT_H

typedef struct ControlGrid ControlGrid;
typedef struct Grid Grid;

    struct ControlGrid {
        Grid* First;
        Grid* Last;
    };

    struct Grid {
        int** Tab;
        int lignes;
        int colonnes;
        Grid* next;
        Grid* previous;
    };

#endif // STRUCT_H