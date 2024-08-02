#include "debug.h"
#include "cell.h"

#include <stdio.h>


void temp_debug_file(FILE *f) {

  for(int i = 0; i < WINDOW_W / SCALE; ++i) {
    for(int j = 0; j < WINDOW_H / SCALE; ++j) {
      fprintf(f, "x: %lld | y: %lld | state: %lld  --- ", cells[i][j]->x, cells[i][j]->y, cells[i][j]->state);
      
    }
  }
  fprintf(f, "\n");
}
