
#include "render.h"
#include "cell.h"
#include  "debug.h"

#define FONT_SIZE 2

//Draw statestics
void draw_stats(SDL_Renderer *renderer, TTF_Font *font) {
  
  /*Draw rect*/
  SDL_SetRenderDrawColor(renderer, 100, 80, 80, 230);
  SDL_Rect box = {0, WINDOW_H - 200, 300, 200};
  SDL_RenderFillRect(renderer, &box);

  SDL_Color white = {255, 255, 255, 255};
  
  /*Draw text fps*/
  char fps_txt[20];
  SDL_Rect msg_rect_fps = {0, WINDOW_H - 200, 75 * FONT_SIZE, 25 * FONT_SIZE};
  snprintf(fps_txt, sizeof(fps_txt),"FPS: %.2f", debug_data->fps);
  SDL_Surface *surf_msg; 
  SDL_Texture *msg; 

  surf_msg = TTF_RenderText_Solid(font, fps_txt, white);
  msg = SDL_CreateTextureFromSurface(renderer, surf_msg);
  
  SDL_RenderCopy(renderer, msg, NULL, &msg_rect_fps);

  /*tps*/
  memset(fps_txt, 0, sizeof(fps_txt));
  SDL_Rect msg_rect_tpf = {0, WINDOW_H - 200 + 50, 100 * FONT_SIZE, 25 * FONT_SIZE};
  snprintf(fps_txt, sizeof(fps_txt), "TPF: %.5f", debug_data->tpf);
  surf_msg = TTF_RenderText_Solid(font, fps_txt, white);
  msg = SDL_CreateTextureFromSurface(renderer, surf_msg);
  SDL_RenderCopy(renderer, msg, NULL, &msg_rect_tpf);

  /*alive cells*/
  memset(fps_txt, 0, sizeof(fps_txt));
  SDL_Rect msg_rect_a_cells = {0, WINDOW_H - 200 + 100, 75 * FONT_SIZE, 25 * FONT_SIZE};
  snprintf(fps_txt, sizeof(fps_txt), "A CELLS: %.2d", debug_data->a_cells);
  surf_msg = TTF_RenderText_Solid(font, fps_txt, white);
  msg = SDL_CreateTextureFromSurface(renderer, surf_msg);
  SDL_RenderCopy(renderer, msg, NULL, &msg_rect_a_cells);

  /*dead cells*/
  memset(fps_txt, 0, sizeof(fps_txt));
  SDL_Rect msg_rect_d_cells = {0, WINDOW_H - 200 + 150, 75 * FONT_SIZE, 25 * FONT_SIZE};
  snprintf(fps_txt, sizeof(fps_txt), "D CELLS: %.2d", debug_data->d_cells);
  surf_msg = TTF_RenderText_Solid(font, fps_txt, white);
  msg = SDL_CreateTextureFromSurface(renderer, surf_msg);
  SDL_RenderCopy(renderer, msg, NULL, &msg_rect_d_cells);
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
