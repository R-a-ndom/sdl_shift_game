#include <SDL2/SDL.h>

#include "base.h"
#include "sdl_serv.h"
#include "sdl_simple_draw.h"
#include "sdl_digit_seven.h"

#include "field.h"
#include "draws.h"
#include "shift.h"

static void player_turn(game_field field, cell_pos* pos, int app_state) {
  switch (app_state) {
    case state_move_up : {
      if ( pos->cell_row < field_size-1 ) {
        fill_empty_pos(field, pos, 1, 0);
      }
      break;
    }
    case state_move_down : {
      if ( pos->cell_row > 0 ) {
        fill_empty_pos(field, pos, -1, 0);
      }
      break;
    }
    case state_move_left : {
      if ( pos->cell_col < field_size-1 ) {
        fill_empty_pos(field, pos, 0, 1);
      }
      break;
    }
    case state_move_right : {
      if ( pos->cell_col > 0 ) {
        fill_empty_pos(field, pos, 0, -1);
      }
      break;
    }
    default : {
      break;
    }
  }  /* switch (app_state) */
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
  cell_pos empty_cell_pos;
#ifdef DEBUG  /* debug mode - draw a littse cross in screen middle */
  cross_state debug_cross_state;
  debug_cross_state.size = debug_cross_min;
  debug_cross_state.growing = cross_grow;
#endif

  empty_cell_pos = empty_cell_begin_pos;
  copy_field(source_field, main_field);
  app_state = state_continue;

/* MAIN CYCLE */

  while (app_state != state_quit) {

    while ( SDL_PollEvent(&main_ev) ) {
      switch (main_ev.type) {
        case SDL_QUIT: {
          app_state = state_quit;
          printf("QUIT event!\n");
          break;
        }
        case SDL_KEYDOWN: {
          app_state = handle_keyboard_event(&main_ev);
          player_turn(main_field, &empty_cell_pos, app_state);
          break;
        }
      }  /* switch (.....) */
    }    /* while event... */
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
