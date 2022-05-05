#include <SDL2/SDL.h>

#include "base.h"
#include "sdl_serv.h"
#include "sdl_simple_draw.h"
#include "sdl_digit_seven.h"
#include "draws.h"
#include "shift.h"

const game_field source_field =
  { {  1,  2,  3,  4 },
    {  5,  6,  7,  8 },
    {  9, 10, 11, 12 }, 
    { 13, 14, 15,  0 } };

const cell_pos begin_empty_cell_pos = { 3, 3 };

static void copy_field(const game_field source, game_field dest)
{
  int i, j;
  for(i = 0; i < field_size; i++) {
    for(j = 0; j < field_size; j++) {
      dest[i][j] = source[i][j];
    }
  }
}

static int handle_keyboard_event(SDL_Event* event) {
  switch ( event->key.keysym.scancode ) {
    case SDL_SCANCODE_UP : {
      return state_move_up;
      break;
    }
    case SDL_SCANCODE_DOWN : {
      return state_move_down;
      break;
    }
    case SDL_SCANCODE_LEFT : {
      return state_move_left;
      break;
    }
    case SDL_SCANCODE_RIGHT : {
      return state_move_right;
      break;
    }
    case SDL_SCANCODE_ESCAPE : {
      return state_quit;
      break;
    }
    default : {
      break;
    }
  } /* switch */
  return state_continue;
}

void shift_run(SDL_Renderer* rend) {
  SDL_Event main_ev;
  int app_state;
  game_field main_field;
#ifdef DEBUG  /* debug mode - draw a littse cross in screen middle */
  cross_state debug_cross_state;
  debug_cross_state.size = debug_cross_min;
  debug_cross_state.growing = cross_grow;
#endif

  copy_field(source_field, main_field);

/* MAIN CYCLE */

  while (app_state != state_quit) {

    app_state = state_continue;

    while ( SDL_PollEvent(&main_ev) ) {
      switch (main_ev.type) {
        case SDL_QUIT: {
          app_state = state_quit;
          printf("QUIT event!\n");
          break;
        }
        case SDL_KEYDOWN: {
          app_state = handle_keyboard_event(&main_ev);
          break;
        }
      }
    }  // while event...
    SDL_CHANGE_COLOR(rend, c16_black, SDL_ALPHA_OPAQUE);
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
