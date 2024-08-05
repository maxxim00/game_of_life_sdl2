#include <SDL2/SDL.h>
#include <stdbool.h>

#include "init.h"
#include "loop.h"
#include "cell.h"

int main() {
  SDL_Window *window;
  SDL_Renderer * renderer;

  init_sdl(&window, &renderer);
  init_cells();

  main_loop(renderer);

  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  return 0;
}
