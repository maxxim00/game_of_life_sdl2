#include <SDL2/SDL.h>
#include <stdbool.h>

#include "init.h"
#include "loop.h"
#include "cell.h"

//Add stats display (stat_display branch)

int main() {
  SDL_Window *window;
  SDL_Renderer * renderer;

  //Initialize SDL2 & cells
  init_sdl(&window, &renderer);
  init_cells();

  //Running the main loop
  main_loop(renderer);

  //Destroy & quit
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  TTF_Quit();
  SDL_Quit();
  return 0;
}
