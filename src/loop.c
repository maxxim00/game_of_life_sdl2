#include <stdbool.h>

#include "loop.h"
#include "cell.h"
#include "render.h"
#include "debug.h"

#define FRAME_DURATION_MS 16.666666

//Private
static void handle_events(bool *running, bool *show_stats);

void main_loop(SDL_Renderer *renderer) {
  bool running = true;
  bool show_stats = false;

  Uint64 start, end;
  double elapsed;
  Uint64 frequency = SDL_GetPerformanceFrequency();
  
  while(running) {
    start = SDL_GetPerformanceCounter();

    //Update
    handle_events(&running, &show_stats);
    update_cells();

    //Draw
    clear_screen(renderer);
    
    draw_cells(renderer);
    draw_grid_borders(renderer);

    //stats
    if(show_stats)draw_stats(renderer);
  
    SDL_RenderPresent(renderer);

    end = SDL_GetPerformanceCounter();

    
    elapsed = (end - start) / (double)frequency * 1000.f;
    if(elapsed < FRAME_DURATION_MS - elapsed) {
      SDL_Delay((Uint32)(FRAME_DURATION_MS - elapsed));
    }
    debug_data->fps = 10.0f / ((end - start) / (double)frequency * FRAME_DURATION_MS);
    debug_data->tpf = elapsed / 1000.f;
  }
}

static void handle_events(bool *running, bool *show_stats) {
  SDL_Event event;
  while(SDL_PollEvent(&event)) {
    switch(event.type) {
      case SDL_KEYDOWN:
        if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
          *running = false;
        }
        if(event.key.keysym.scancode == SDL_SCANCODE_D && *show_stats == true){*show_stats = false;}else{*show_stats = true;}
        break;
      case SDL_QUIT:
        *running = false;
        break;
    }
  }
}
