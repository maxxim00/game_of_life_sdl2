#include <stdbool.h>

#include "loop.h"
#include "cell.h"
#include "render.h"

#define FRAME_DURATION_MS 16.666

//Private
static void handle_events(bool *running, bool *fps_limit, bool *fps_state);

void main_loop(SDL_Renderer *renderer) {
  bool running = true;
  bool fps_limit = true;
  bool fps_state = true;

  int first_iter = 1;

  Uint64 start, end;
  double elapsed;
  Uint64 frequency = SDL_GetPerformanceFrequency();
  
  int count = 0;

  while(running) {
  
    if(fps_limit) {
      start = SDL_GetPerformanceCounter();
    }
    
    handle_events(&running, &fps_limit, &fps_state);



    if(first_iter || count >= 20) {
    
    clear_screen(renderer);

    
    draw_cells(renderer);
    draw_grid_borders(renderer);
  
    
    update_cells();

    SDL_RenderPresent(renderer);

      first_iter = 0;
    }

    count += 1;
    if(count > 20) {
      count = 0;
    } 


    printf("fps_state: %d\n", fps_state);    

    if(fps_limit) {
      end = SDL_GetPerformanceCounter();
      elapsed = (end - start) / (double)frequency * 1000.f;
      if(elapsed < FRAME_DURATION_MS - elapsed) {
        SDL_Delay((Uint32)(FRAME_DURATION_MS - elapsed));
      }
    }
  }
}

static void handle_events(bool *running, bool *fps_limit, bool *fps_state) {
  SDL_Event event;
  while(SDL_PollEvent(&event)) {
    switch(event.type) {
      
      case SDL_KEYDOWN:
        if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
          *running = false;
        }

        if (*fps_state && event.key.keysym.scancode == SDL_SCANCODE_F) {
          *fps_limit = false; 
          *fps_state = true;
          printf("CLICK");
        } 
        if (*fps_state == false && event.key.keysym.scancode == SDL_SCANCODE_F) {
          *fps_limit = true; 
          *fps_state = false;
        }
        break;

      case SDL_QUIT:
        *running = false;
        break;
    }
  }
}
