#include <stdbool.h>

#include "loop.h"
#include "cell.h"
#include "render.h"
#include "debug.h"
#include "init.h"

//Private
static void handle_events(bool *running, bool *show_stats);

void main_loop(SDL_Renderer *renderer) {
  bool running = true;
  bool show_stats = false;

  Uint64 perf_freq = SDL_GetPerformanceFrequency();
  Uint64 start, elapsed;
  double fps = 0, frame_time = 16.66666f;
  
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
    if(show_stats)draw_stats(renderer, font);
  
    SDL_RenderPresent(renderer);

    //frame rate cap and time per frame
    elapsed = SDL_GetPerformanceCounter() - start;
    double elapsed_ms= ((double)elapsed / perf_freq) * 1000.0f;

    if(elapsed_ms <= frame_time) {
      double delay_time = frame_time - elapsed_ms;
      SDL_Delay(delay_time);
      fps = 1000.0f / (delay_time + elapsed_ms);
    }else {
      fps = 1000.0f / elapsed_ms;
    }
    debug_data->fps = fps;
    debug_data->tpf = elapsed_ms;
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
        if(event.key.keysym.scancode == SDL_SCANCODE_D && *show_stats == true){*show_stats = false;}
        else if(event.key.keysym.scancode == SDL_SCANCODE_D && *show_stats == false){*show_stats = true;}
        break;
      case SDL_QUIT:
        *running = false;
        break;
    }
  }
}
