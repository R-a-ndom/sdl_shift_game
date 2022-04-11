#include <SDL2/SDL.h>

#include "base.h"
#include "sdl_simple_draw.h"
#include "draws.h"
#include "shift.h"

const game_field start_field =
  {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,0}};

static void copy_field(const game_field source, game_field dest)
{
  int i, j;
  for(i = 0; i < field_size; i++) {
    for(j = 0; j < field_size; j++) {
      dest[i][j] = source[i][j];
    }
  }
}

void shift_run(SDL_Renderer* rend) {
  SDL_Event main_ev;
  SDL_bool app_is_running;
  game_field main_field;
#ifdef DEBUG
  cross_state debug_cross_state;
  debug_cross_state.size = debug_cross_min;
  debug_cross_state.growing = cross_grow;

#endif

  copy_field(start_field, main_field);
  app_is_running = SDL_TRUE;
  while (app_is_running == SDL_TRUE) {

    while ( SDL_PollEvent(&main_ev) ) {
      switch (main_ev.type) {
        case SDL_QUIT: {
          app_is_running = SDL_FALSE;
          printf("QUIT event!\n");
          break;
        }
      }
    }  // while event...
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
    SDL_RenderClear(rend);

    draw_statics(rend);
#ifdef DEBUG
    debug_draw_cross(rend, debug_cross_state);
    debug_next_cross_state(&debug_cross_state);
#endif
    draw_all_field(rend, main_field);

    SDL_RenderPresent(rend);
    SDL_Delay(FPS_50);
  } // while app_is_running...
}
