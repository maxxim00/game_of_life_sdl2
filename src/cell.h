#ifndef CELL_H
#define CELL_H

#include <SDL2/SDL.h>

#define SCALE 4

#define WINDOW_W  1000
#define WINDOW_H  1000

#define GRID_W (WINDOW_W / SCALE)
#define GRID_H (WINDOW_H / SCALE)

//Structure of "cell"
struct cell {
  int x, y, state;
};
typedef struct cell cell;

//Extern cell variable
extern cell cells[GRID_W * GRID_H];

//Public functions
void init_cells();
void update_cells();

#endif
