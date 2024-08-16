#ifndef INIT_H
#define INIT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h> 

extern TTF_Font *font;

void init_sdl(SDL_Window **window, SDL_Renderer **renderer);

#endif
