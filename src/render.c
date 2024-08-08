#include "render.h"
#include "cell.h"
#include  "debug.h"

//Draw statestics
void draw_stats(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 200, 80, 80, 230);
  SDL_Rect box = {0, WINDOW_H, 300, -200};

  SDL_RenderFillRect(renderer, &box);

  //temp
  printf("\nFPS: %f\nAlive cells: %d\nDead cels: %d\nAll cells: %d\n", 
         debug_data->fps, debug_data->a_cells, debug_data->d_cells, debug_data->all_cells);
}

//Draw cells
void draw_cells(SDL_Renderer *renderer) {  
SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
SDL_Rect rect;
for(int i = 0; i < GRID_W; ++i) {
    for(int j = 0; j < GRID_H; ++j) {
      int index = i * GRID_H + j;
      if(cells[index].state == 1) {
        rect.x = cells[index].x * SCALE + 1;
        rect.y = cells[index].y * SCALE + 1;
        rect.w = SCALE - 1;
        rect.h = SCALE - 1;

        SDL_RenderFillRect(renderer, &rect);
      }
    }
  }
}

//Draw grid borders
void draw_grid_borders(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 200, 100, 100, 255);
  
  SDL_RenderDrawLine(renderer, 0, 0, WINDOW_W, 0);
  SDL_RenderDrawLine(renderer, 0, 0, 0, WINDOW_H);
  SDL_RenderDrawLine(renderer, WINDOW_W, 0, WINDOW_W, WINDOW_H);
  SDL_RenderDrawLine(renderer, 0, WINDOW_H, WINDOW_W, WINDOW_H);
}

//Draw all grid lines (Vertical + Horizontal)
void draw_grid_lines(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);

  for(int i = 0; i < GRID_W + 1; i++) {
    SDL_RenderDrawLine(renderer, i * SCALE, 0, i * SCALE, WINDOW_H);
  }

  for(int i = 0; i < GRID_H + 1; i++) {
    SDL_RenderDrawLine(renderer, 0, i * SCALE, WINDOW_W, i * SCALE);
  } 
}

//Clear screen
void clear_screen(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
  SDL_RenderClear(renderer);
}
