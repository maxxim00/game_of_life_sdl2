#include <time.h>

#include "init.h"
#include "cell.h"

//Initialize SDL2
void init_sdl(SDL_Window **window, SDL_Renderer **renderer) {
  if(SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
    exit(1);
  }  
  
  *window = SDL_CreateWindow("Conway's Game of Life", 
  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN);
  if(*window == NULL) {
    fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
    SDL_Quit();
    exit(1);
  }

  *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
  if(*renderer == NULL) {
    fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
    SDL_DestroyWindow(*window);
    SDL_Quit();
    exit(1);
  }

  srand(time(NULL));
}
