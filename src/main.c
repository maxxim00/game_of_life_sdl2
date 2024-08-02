#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "core.h"
#include "cell.h"
#include "screen.h"
#include "debug.h"

int main() {
  SDL_Init(SDL_INIT_EVERYTHING);
  srand(time(NULL));

  //SDL core variables
  SDL_Window *window = SDL_CreateWindow("conway", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_W, WINDOW_H, 0);
  SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  SDL_Event event;
  FILE *f = fopen("debug", "w");


  //To run before loop  
  init_cells();
  //temp_debug_file(f);

  //sandbox
  
  //timing
  Uint64 start, end;
  double elapsed, time = 1.0f;
    
  bool running = true;
  while(running) {
  start = SDL_GetPerformanceCounter();


    //input check
    if(SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_KEYDOWN:
          running = event.key.keysym.scancode != SDL_SCANCODE_ESCAPE;
          break;
        case SDL_QUIT:
          running = false;
          break;
      }
    }

    clear_screen(renderer);
    
    
    //Drawing on screen
    draw_grid_lines(renderer);
    draw_cells(renderer);

    //Update
    update_cell();

    SDL_RenderPresent(renderer);

   
    //Calculation of delay to keep 60fps
    end = SDL_GetPerformanceCounter();
    elapsed = (end - start) / (float)SDL_GetPerformanceCounter() * 1000.0f;
    SDL_Delay(floor(16.666f - elapsed));
    time += 0.1f;
  }

  //Destroy and quit
  fclose(f);
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  return 0;
}
