#include <SDL2/SDL.h>

#include "base.h"
#include "draws.h"
#include "shift.h"

const game_field start_field =
  {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,0}};

void copy_field(game_field source, game_field dest)
{
  int i, j;
  for(i = 0; i < field_size; i++) {
    for(j = 0; j < field_size; j++) {
      dest[i][j] = source[i][j];
    }
  }
}

void shift_run(SDL_Renderer* rend) {
  game_field main_field;

  copy_field(start_field, main_field);
  SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
  SDL_RenderClear(rend);

  draw_statics(rend);
  draw_all_field(rend, main_field);

  SDL_RenderPresent(rend);
  SDL_Delay(5000);
}
