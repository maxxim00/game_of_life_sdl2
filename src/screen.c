#include "screen.h"
#include "cell.h"

//Draw all the cells
void draw_cells(SDL_Renderer *renderer) {  
SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
SDL_Rect rect;

for(int i = 0; i < X; ++i) {
    for(int j = 0; j < Y; ++j) {
      
      if(cells[i][j]->state == 1) {
        //Set rect parameters
        rect.x = cells[i][j]->x * SCALE + 1;
        rect.y = cells[i][j]->y * SCALE + 1;
        rect.w = SCALE - 1;
        rect.h = SCALE - 1;

        //Draw rect
        SDL_RenderFillRect(renderer, &rect);
      }
    }
  }
}

//Draw grid lines
void draw_grid_lines(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);

  //Vertical
  for(int i = 0; i < (X) + 1; i++) {
    SDL_RenderDrawLine(renderer, i * SCALE, 0, i * SCALE, WINDOW_H);
  }

  //Horizontal
  for(int i = 0; i < (Y) + 1; i++) {
    SDL_RenderDrawLine(renderer, 0, i * SCALE, WINDOW_W, i * SCALE);
  } 
}

