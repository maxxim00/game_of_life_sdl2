#include "core.h"

//Clear the screen
void clear_screen(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 226, 226, 226, 255);
  SDL_RenderClear(renderer);
}
