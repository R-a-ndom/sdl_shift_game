#include <SDL2/SDL.h>

#include "sdl_serv.h"
#include "sdl_simple_draw.h"
#include "wild_math.h"

#include "base.h"
#include "draws.h"

static const SDL_Point field_draw_start = {50, 50};

#ifdef DEBUG
static void debug_draw_cross(SDL_Renderer* rend)
{
  SDL_SetRenderDrawColor(rend, 150, 220, 150, 255);
  SDL_RenderDrawLine(rend,
                     HALF_SCREEN_WIDTH, 0,
                     HALF_SCREEN_WIDTH,  main_win_height);
  SDL_RenderDrawLine(rend,
                     0, HALF_SCREEN_HEIGHT,
                     main_win_width, HALF_SCREEN_HEIGHT);
}


void draw_statics(SDL_Renderer* rend)
{
#ifdef DEBUG
  debug_draw_cross(rend);
#endif
}

#endif