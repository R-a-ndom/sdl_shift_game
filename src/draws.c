#include <SDL2/SDL.h>

#include "sdl_serv.h"
#include "sdl_simple_draw.h"
#include "wild_math.h"

#include "base.h"
#include "draws.h"

static const SDL_Point field_draw_start = {125, 105};

#ifdef DEBUG

void debug_next_cross_state(cross_state* state)
{
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
                             cross_state c_state)
{
  SDL_SetRenderDrawColor(rend, 220, 120, 120, 255); // yellow cross in middle
  SDL_RenderDrawLine(rend,
                     HALF_SCREEN_WIDTH, HALF_SCREEN_HEIGHT - c_state.size,
                     HALF_SCREEN_WIDTH, HALF_SCREEN_HEIGHT + c_state.size);
  SDL_RenderDrawLine(rend,
                     HALF_SCREEN_WIDTH - c_state.size, HALF_SCREEN_HEIGHT,
                     HALF_SCREEN_WIDTH + c_state.size, HALF_SCREEN_HEIGHT);
}

#endif

void draw_statics(SDL_Renderer* rend)
{

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
                          int h_pos, int v_pos)
{
  SDL_Point cell_draw_start;
  cell_draw_start.x = calc_cell_horiz_pos_start(h_pos);
  cell_draw_start.y = calc_cell_vert_pos_start(v_pos);
  sdl_draw_chamfered_frame(rend,
                           cell_draw_start,
                           cell_width, cell_height,
                           cell_chamfer);
}

void draw_all_field(SDL_Renderer* rend, const game_field field)
{
  SDL_SetRenderDrawColor(rend, 100, 100, 220, 255);
  int i, j;
  for(i = 0; i < field_size; i++) {
    for(j = 0; j < field_size; j++) {
      if ( field[i][j] != cell_empty ) {
        draw_one_cell(rend, i, j);
      }
    }
  }
}
