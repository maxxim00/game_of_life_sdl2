#include "cell.h"

#include <stdlib.h>

//Definition
#define PROBABILITY_FACTOR 5

//Private functions
int count_neighbors(int x, int y);
void apply_rules(int neighbors, int x, int y);
void assign_state();

//Declaration 
cell *cells[WINDOW_W / SCALE][WINDOW_H / SCALE];
cell *next_cells[WINDOW_W / SCALE][WINDOW_H / SCALE];

//Public
void update_cell() {
  for(int i = 0; i < WINDOW_W / SCALE; ++i) {
    for(int j = 0; j < WINDOW_H / SCALE; ++j) {

      if(i == 0 || j == 0 || j == (WINDOW_H / SCALE) - 1 || i == (WINDOW_W / SCALE) - 1) {
      //todo: impl the edge calc
      cells[i][j]->state = cells[i][j]->state; 

       }else {
        
        int alive_neighbors = count_neighbors(i, j);
        apply_rules(alive_neighbors, i, j);
      }
    }
  }

  assign_state();
}

//Allocate and initialise cells
void init_cells() {
  for(int i = 0; i < WINDOW_W / SCALE; ++i) {
    for(int j = 0; j < WINDOW_H / SCALE; ++j) {
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
  for(int i = 0; i < WINDOW_W / SCALE; ++i) {
    for(int j = 0; j < WINDOW_H / SCALE; ++j) {
      cells[i][j]->state = next_cells[i][j]->state; 
    }
  }
}

int count_neighbors(int x, int y) {
  int count = 0;

  for(int i = -1; i <= 1; ++i) {
    for(int j = -1; j <= 1; ++j) {
      // Boundary check
      count += cells[i + x][j + y]->state;
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
