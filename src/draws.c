/* * * * * * * * * * * * * * * * * * * *
 *  SDL_SHIFT_GAME                     *
 *                                     *
 *  SDL 2.0 demo - fifteen-like game   *
 *                                     *
 *  DRAWS.C - game elements            *
 *            drawing unit             *
 *                                     *
 *          (c) Alexey Sorokin, 2022   *
 * * * * * * * * * * * * * * * * * * * *
 */

#include <SDL2/SDL.h>

#include "sdl_serv.h"
#include "sdl_simple_draw.h"
#include "wild_math.h"
#include "sdl_digit_seven.h"

#include "base.h"
#include "field.h"
#include "draws.h"

static const SDL_Point field_draw_start = { 125, 105 };
static const SDL_Point big_frame_draw_start = { 110, 90 };

#ifdef DEBUG /* debug mode - drawing little cross in the screen middle */

void debug_next_cross_state(cross_state* state) {
  if (state->growing == cross_grow) {
    if (state->size == debug_cross_max) {
      state->growing = cross_shrink;
    } else {
      (state->size)++;
    }
  } else {
    if (state->size == debug_cross_min) {
      state->growing = cross_grow;
    } else {
      (state->size)--;
    }
  }
}

void debug_draw_cross(SDL_Renderer* rend,
                      cross_state c_state) {
  SDL_CHANGE_COLOR(rend, c16_yellow, SDL_ALPHA_OPAQUE);
  SDL_RenderDrawLine(rend,
                     HALF_SCREEN_WIDTH, HALF_SCREEN_HEIGHT - c_state.size,
                     HALF_SCREEN_WIDTH, HALF_SCREEN_HEIGHT + c_state.size);
  SDL_RenderDrawLine(rend,
                     HALF_SCREEN_WIDTH - c_state.size, HALF_SCREEN_HEIGHT,
                     HALF_SCREEN_WIDTH + c_state.size, HALF_SCREEN_HEIGHT);
}

#endif

void draw_statics(SDL_Renderer* rend) {
  SDL_CHANGE_COLOR(rend, c16_magenta, SDL_ALPHA_OPAQUE);
  sdl_draw_chamfered_frame(rend,
                           big_frame_draw_start,
                           big_frame_width, big_frame_height,
                           big_frame_chamfer);
}

static int calc_cell_horiz_pos_start(int pos) {
  if (pos == 0) {
    return field_draw_start.x;
  } else {
    return field_draw_start.x + pos*(cell_width + cell_gap);
  }
}

static int calc_cell_vert_pos_start(int pos) {
  if (pos == 0) {
    return field_draw_start.y;
  } else {
    return field_draw_start.y + pos*(cell_height + cell_gap);
  }
}

static void draw_one_cell(SDL_Renderer* rend,
                          int h_pos, int v_pos, int value) {
  SDL_Point cell_draw_start;
  SDL_Point value_draw_start;

  cell_draw_start.x = calc_cell_horiz_pos_start(v_pos);
  cell_draw_start.y = calc_cell_vert_pos_start(h_pos);

  value_draw_start.x = cell_draw_start.x + cell_value_draw_gap;
  value_draw_start.y = cell_draw_start.y + cell_value_draw_gap;

  if ( value < 10 ) {
    value_draw_start.x += cell_value_digit_length ;
  }

  sdl_draw_chamfered_frame(rend,
                           cell_draw_start,
                           cell_width, cell_height,
                           cell_chamfer);
  sdl_draw_seven_digit_number(rend,
                              seg_fat, cell_value_digit_length,
                              value_draw_start, value);
}

void draw_all_field(SDL_Renderer* rend, const game_field field) {
  int row, col;
  for(row = 0; row < field_size; row++) {
    for(col = 0; col < field_size; col++) {
      if ( field[row][col] != cell_empty ) {
        if ( field[row][col] == source_field[row][col] ) {
          SDL_CHANGE_COLOR(rend, c16_cyan, SDL_ALPHA_OPAQUE);
        } else {
          SDL_CHANGE_COLOR(rend, c16_gray, SDL_ALPHA_OPAQUE);
        }
        draw_one_cell(rend, row, col, field[row][col]);
      }
    }
  }
}
