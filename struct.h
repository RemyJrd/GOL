typedef struct ControlGrid ControlGrid;
    struct Node {
        int data;
        struct Grid* First;
        struct Grid* Last;
    };

typedef struct Grid Grid;
    struct Grid {
        int** Tab;
        struct Grid* next;
        struct Grid* previous;
    };