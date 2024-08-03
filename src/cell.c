#include "cell.h"

#include <stdlib.h>

//Definition
#define PROBABILITY_FACTOR 2

//Private functions
int count_neighbors(int x, int y);
void apply_rules(int neighbors, int x, int y);
void assign_state();

//Declaration 
cell *cells[X][Y];
cell *next_cells[X][Y];

//Variables

//Public
void update_cell() {
  for(int i = 0; i < X; ++i) {
    for(int j = 0; j < Y; ++j) {
       
      int alive_neighbors = count_neighbors(i, j);
      apply_rules(alive_neighbors, i, j);
    }
  }
  assign_state();
}

//Allocate and initialise cells
void init_cells() {
  for(int i = 0; i < X; ++i) {
    for(int j = 0; j < Y; ++j) {
      cells[i][j] = malloc(sizeof(cell));
      next_cells[i][j] = malloc(sizeof(cell));

      cells[i][j]->x = i;
      cells[i][j]->y = j;

      //Give random states (1 in PROBABILITY_FACTOR)
      cells[i][j]->state = (rand() % PROBABILITY_FACTOR == 1) ? 1 : 0;
    }
  }
}

//Private
void assign_state() {
  for(int i = 0; i < X; ++i) {
    for(int j = 0; j < Y; ++j) {
      cells[i][j]->state = next_cells[i][j]->state; 
    }
  }
}

int count_neighbors(int x, int y) {
  int count = 0;
  int modx = 0;
  int mody = 0;
  
  for(int i = -1; i < 2; ++i) {
    for(int j = -1; j < 2; ++j) {
      modx = ((x + i + X) % (X));
      mody = ((y + j + Y) % (Y));
      count += cells[modx][mody]->state;
    }
  }
  count -= cells[x][y]->state;
  return count;
}

//Apply Conway's rules
void apply_rules(int neighbors, int x, int y) {
  if(cells[x][y]->state == 0 && neighbors == 3) {
    next_cells[x][y]->state = 1;
  } 
  else if(cells[x][y]->state == 1 && (neighbors < 2 || neighbors > 3)) {
    next_cells[x][y]->state = 0;
  }
}
