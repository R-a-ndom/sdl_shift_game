/* * * * * * * * * * * * * * * * * * * *
 *  SDL_SHIFT_GAME                     *
 *                                     *
 *  SDL 2.0 demo - fifteen-like game   *
 *                                     *
 *  MAIN.C - main file                 *
 *                                     *
 *          (c) Alexey Sorokin, 2022   *
 * * * * * * * * * * * * * * * * * * * *
 */

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "wild_math.h"

#include "sdl_serv.h"
#include "sdl_simple_draw.h"
#include "sdl_digit_seven.h"

#include "base.h"
#include "field.h"
#include "shift.h"

const char main_win_caption[] = "SHIFT (SDL 2.0 demo)";

/* *** *** *** *** *** *** *** ***
   *** ***  INT MAIN(...)  *** ***
   *** *** *** *** *** *** *** *** */
int main(int argc, char *argv[])
{
  SDL_Window* main_win = NULL;
  SDL_Renderer* main_rend = NULL;
//  SDL_Event app_event;

  app_init(main_win_caption, &main_win, &main_rend);
  printf("SDL_Shift init...\n");

  shift_run(main_rend);

  app_close(main_win, main_rend, EXIT_SUCCESS);
  return 0;
}