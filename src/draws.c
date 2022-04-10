#include <SDL2/SDL.h>

#include "sdl_serv.h"
#include "sdl_simple_draw.h"
#include "wild_math.h"

#include "base.h"
#include "draws.h"

static const SDL_Point field_draw_start = {125, 105};

#ifdef DEBUG
static void debug_draw_cross(SDL_Renderer* rend)
{
  SDL_SetRenderDrawColor(rend, 150, 220, 150, 255);
  SDL_RenderDrawLine(rend,
                     HALF_SCREEN_WIDTH, HALF_SCREEN_HEIGHT - debug_cross_size,
                     HALF_SCREEN_WIDTH, HALF_SCREEN_HEIGHT + debug_cross_size);
  SDL_RenderDrawLine(rend,
                     HALF_SCREEN_WIDTH - debug_cross_size, HALF_SCREEN_HEIGHT,
                     HALF_SCREEN_WIDTH + debug_cross_size, HALF_SCREEN_HEIGHT);
}


void draw_statics(SDL_Renderer* rend)
{
#ifdef DEBUG
  debug_draw_cross(rend);
#endif
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

void draw_all_field(SDL_Renderer* rend, game_field field)
{
  int i, j;
  for(i = 0; i < field_size; i++) {
    for(j = 0; j < field_size; j++) {
      if ( field[i][j] != cell_empty ) {
        draw_one_cell(rend, i, j);
      }
    }
  }
}

#endif