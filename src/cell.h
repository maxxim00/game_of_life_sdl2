#ifndef CELL_H
#define CELL_H

#define WINDOW_W  800
#define WINDOW_H  800

#define SCALE 5

#define X WINDOW_W / SCALE
#define Y WINDOW_H / SCALE

//Cell structure definition
struct cell {
  int x, y, state;
};
typedef struct cell cell;

//2D array of cells
extern cell *cells[X][Y];
extern cell *next_cells[X][Y];

//Initialize cells with random states
void init_cells();

//Update the cells according to conway's rules
void update_cell();

#endif
