#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "core.h"
#include "cell.h"
#include "screen.h"

int main() {
  SDL_Init(SDL_INIT_EVERYTHING);
  srand(time(NULL));

  //SDL core variables
  SDL_Window *window = SDL_CreateWindow("conway", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_W, WINDOW_H, 0);
  SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  SDL_Event event;

  //Run before loop  
  init_cells();

  //counter for generations
  unsigned long long int gen_count = 0;
  
  //FPS TEMP
  Uint64 start, end;
  double elapsed, time = 1.0f;
    
  bool running = true;
  while(running) {
  //gen counter to draw on screen
  //printf("Generation: %llu\n", gen_count);
  
  start = SDL_GetPerformanceCounter(); //TEMP

        //Input check
    if(SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_KEYDOWN:
          //Escape
          running = event.key.keysym.scancode != SDL_SCANCODE_ESCAPE;
          // //Temp update test
          // if(event.key.keysym.sym == SDLK_UP) {
          //   update_cell();
          // }
          break;
        case SDL_QUIT:
          running = false;
          break;
      }
    }

    clear_screen(renderer);
    
    
    //Drawing
    draw_grid_lines(renderer);
    draw_cells(renderer);

    //Update
    update_cell();


    SDL_RenderPresent(renderer);
  
    //Calculate delay TEMP
    end = SDL_GetPerformanceCounter();
    elapsed = (end - start) / (float)SDL_GetPerformanceCounter() * 1000.0f;
    SDL_Delay(floor(16.666f - elapsed));
    time += 0.1f;

    
    gen_count++;
  }

  //Destroy and quit
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  return 0;
}
