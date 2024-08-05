#ifndef CELL_H
#define CELL_H

#include <SDL2/SDL.h>

#define SCALE 4

#define WINDOW_W  800
#define WINDOW_H  800

#define GRID_W (WINDOW_W / SCALE)
#define GRID_H (WINDOW_H / SCALE)

struct cell {
  int x, y, state;
};
typedef struct cell cell;

extern cell cells[GRID_W * GRID_H];

void init_cells();
void update_cells();

void clear_screen(SDL_Renderer *renderer);

#endif
