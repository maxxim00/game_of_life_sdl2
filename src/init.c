#include <time.h>

#include "init.h"
#include "cell.h"
#include "debug.h"

//Initialize SDL2
void init_sdl(SDL_Window **window, SDL_Renderer **renderer) {
  if(SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
    exit(1);
  }  
  
  if (TTF_Init() != 0) {
      printf("TTF_Init Error: %s\n", TTF_GetError());
      SDL_Quit();
      exit(1);
    }
  TTF_Font *font = TTF_OpenFont("assets/fonts/roboto.ttf", 24);

  *window = SDL_CreateWindow("Conway's Game of Life", 
  SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN);
  if(*window == NULL) {
    fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
    TTF_Quit();
    SDL_Quit();
    exit(1);
  }

  *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
  if(*renderer == NULL) {
    fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
    SDL_DestroyWindow(*window);
    TTF_Quit();
    SDL_Quit();
    exit(1);
  }

  SDL_SetRenderDrawBlendMode(*renderer, SDL_BLENDMODE_BLEND);  

  srand(time(NULL));
  debug_data = malloc(sizeof(stat_data));
}
