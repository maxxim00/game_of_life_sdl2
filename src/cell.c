#include "cell.h"

#include <stdlib.h>

#define PROBABILITY_FACTOR 2

//Private functions
int count_neighbors(int x, int y);
void apply_rules(int neighbors, int x, int y);
void assign_state();

//Declaration cell variable
cell cells[GRID_W * GRID_H];
cell next_cells[GRID_W * GRID_H];

//Public functions
//Update the cells: count neighbors, apply rules and assign state
void update_cells() {
  for(int i = 0; i < GRID_W; ++i) {
    for(int j = 0; j < GRID_H; ++j) {
      
      int alive_neighbors = count_neighbors(i, j);
      apply_rules(alive_neighbors, i, j);
    }
  }
  assign_state();
}

//Initialize cells (position, random state)
void init_cells() {
  for(int i = 0; i < GRID_W; ++i) {
    for(int j = 0; j < GRID_H; ++j) {
      int index = i * GRID_H + j;

      cells[index].x = i;
      cells[index].y = j;
      cells[index].state = (rand() % PROBABILITY_FACTOR == 1) ? 1 : 0; //One in PROBABILITY_FACTOR to be alive
    }
  }
}

//Private functions
void assign_state() {
  for(int i = 0; i < GRID_W; ++i) {
    for(int j = 0; j < GRID_H; ++j) {
      int index = i * GRID_H + j; 
      cells[index].state = next_cells[index].state; 
    }
  }
}

//Count neighboring cells (3x3 square)
int count_neighbors(int x, int y) {
  int count = 0;
  int modx = 0;
  int mody = 0;
  
  for(int i = -1; i < 2; ++i) {
    for(int j = -1; j < 2; ++j) {
      if(i == 0 && j == 0) continue;
      modx = ((x + i + GRID_W) % GRID_W);
      mody = ((y + j + GRID_H) % GRID_H);
      count += cells[modx * GRID_H + mody].state;
    }
  }
  return count;
}

//Apply Conway's rules
void apply_rules(int neighbors, int x, int y) {
  int index = x * GRID_H + y;

  if(cells[index].state == 0 && neighbors == 3) {
    next_cells[index].state = 1;
  } 
  else if(cells[index].state == 1 && (neighbors < 2 || neighbors > 3)) {
    next_cells[index].state = 0;
  }
}
