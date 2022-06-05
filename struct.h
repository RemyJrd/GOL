#ifndef STRUCT_H
#define STRUCT_H

typedef struct ControlGrid ControlGrid;
    struct ControlGrid {
        struct Grid* First;
        struct Grid* Last;
    };

typedef struct Grid Grid;
    struct Grid {
        int** Tab;
        int lignes;
        int colonnes;
        struct Grid* next;
        struct Grid* previous;
    };

#endif // STRUCT_H