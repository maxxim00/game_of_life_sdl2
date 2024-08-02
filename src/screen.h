#ifndef SCREEN_H
#define SCREEN_H

#include <SDL2/SDL.h>

//Draw grid lines
void draw_grid_lines(SDL_Renderer *renderer);

//Draw all cells
void draw_cells(SDL_Renderer *renderer);

//Draw one cell at given index
void draw_one_cell(int x, int y, SDL_Renderer *renderer);

#endif
