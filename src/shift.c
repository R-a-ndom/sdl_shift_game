#include <SDL2/SDL.h>

#include "draws.h"
#include "shift.h"


void shift_run(SDL_Renderer* rend) {

  SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
  SDL_RenderClear(rend);

  draw_statics(rend);

  SDL_RenderPresent(rend);
  SDL_Delay(5000);
}
