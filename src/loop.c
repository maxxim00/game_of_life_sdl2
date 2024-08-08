#include <stdbool.h>

#include "loop.h"
#include "cell.h"
#include "render.h"

#define FRAME_DURATION_MS 16.666

//Private
static void handle_events(bool *running);

void main_loop(SDL_Renderer *renderer) {
  bool running = true;

  Uint64 start, end;
  double elapsed;
  Uint64 frequency = SDL_GetPerformanceFrequency();
  
  while(running) {
    start = SDL_GetPerformanceCounter();

    //Update
    handle_events(&running);
    update_cells();

    //Draw
    clear_screen(renderer);
    
    draw_cells(renderer);
    draw_grid_borders(renderer);
  
    SDL_RenderPresent(renderer);

    end = SDL_GetPerformanceCounter();
    elapsed = (end - start) / (double)frequency * 1000.f;
    if(elapsed < FRAME_DURATION_MS - elapsed) {
      SDL_Delay((Uint32)(FRAME_DURATION_MS - elapsed));
    }
  }
}

static void handle_events(bool *running) {
  SDL_Event event;
  while(SDL_PollEvent(&event)) {
    switch(event.type) {
      case SDL_KEYDOWN:
        if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
          *running = false;
        }
        break;
      case SDL_QUIT:
        *running = false;
        break;
    }
  }
}
