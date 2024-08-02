#include "cell.h"

#include <stdlib.h>

//Defs
#define PROBABILITY_FACTOR 5

//Private functions
int count_neighbors(int x, int y);
void apply_rules(int neighbors, int x, int y);

//Declaration 
cell *cells[WINDOW_W / SCALE][WINDOW_H / SCALE];
cell *next_cells[WINDOW_W / SCALE][WINDOW_H / SCALE];

//Public
void update_cell() {
  for(int i = 0; i < WINDOW_H / SCALE; ++i) {
    for(int j = 0; j < WINDOW_W / SCALE; ++j) {

      if(i == 0 || j == 0 || i == (WINDOW_H / SCALE) - 1 || j == (WINDOW_W / SCALE) - 1) {
      //todo: impl the edge calc
      cells[i][j]->state = cells[i][j]->state; 
      }else {

        int alive_neighbors = count_neighbors(i, j);
        apply_rules(alive_neighbors, i, j);
      }      
    }
  }


  for(int i = 0; i < WINDOW_H / SCALE; ++i) {
    for(int j = 0; j < WINDOW_W / SCALE; ++j) {
      cells[i][j]->state = next_cells[i][j]->state; 
    }
  }
}

//Allocation and initialition of the sells
void init_cells() {
  for(int i = 0; i < WINDOW_W / SCALE; ++i) {
    for(int j = 0; j < WINDOW_H / SCALE; ++j) {
      cells[i][j] = malloc(sizeof(cell));
      next_cells[i][j] = malloc(sizeof(cell));

      cells[i][j]->x = i;
      cells[i][j]->y = j;

      //Giving random states (1 in PROBABILITY_FACTOR) to be alive
      cells[i][j]->state = (rand() % PROBABILITY_FACTOR == 1) ? 1 : 0;
    }
  }
}

//Private
int count_neighbors(int x, int y) {
  int count = 0;

  for(int i = -1; i <= 1; ++i) {
    for(int j = -1; j <= 1; ++j) {
      // Boundary checks
      count += cells[x + i][y + j]->state;
    }
  }

  count -= cells[x][y]->state;

  return count;
}

void apply_rules(int neighbors, int x, int y) {
  if(cells[x][y]->state == 0 && neighbors == 3) {
    next_cells[x][y]->state = 1;
  } 
  else if(cells[x][y]->state == 1 && (neighbors < 2 || neighbors > 3)) {
    next_cells[x][y]->state = 0;
  }
}
