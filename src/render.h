#ifndef RENDER_H
#define RENDER_H

#include <SDL2/SDL.h>

//Grid
void draw_grid_lines(SDL_Renderer *renderer);
void draw_grid_borders(SDL_Renderer *renderer);

//Cells
void draw_cells(SDL_Renderer *renderer);

void draw_stats(SDL_Renderer *renderer);
void clear_screen(SDL_Renderer *renderer);

#endif
