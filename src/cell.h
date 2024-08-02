#ifndef CELL_H
#define CELL_H

#define WINDOW_W  800
#define WINDOW_H  800
#define SCALE 6

//Cell structure definition
struct cell {
  long long int x, y, state;
};
typedef struct cell cell;

//2D array of cells
extern cell *cells[WINDOW_W / SCALE][WINDOW_H / SCALE];
extern cell *next_cells[WINDOW_W / SCALE][WINDOW_H / SCALE];

//Initialize cells with random states
void init_cells();

//Update the cells according to conway's rules
void update_cell();

#endif
