#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "sdl_serv.h"

/* screen size */

const int main_win_height = 720;
const int main_win_width = 1280;

/* colors in 16-color palette */

const rgb_color_def c16_black = {   0,   0,   0 };

const rgb_color_def c16_red     = { 255,   0,   0 };
const rgb_color_def c16_green   = {   0, 255,   0 };
const rgb_color_def c16_blue    = {   0,   0, 255 };
const rgb_color_def c16_yellow  = { 255, 255,   0 };
const rgb_color_def c16_magenta = { 255,   0, 255 };
const rgb_color_def c16_cyan    = {   0, 255, 255 };

const rgb_color_def c16_white = { 255, 255, 255 };

int app_close(SDL_Window* app_win, SDL_Renderer* app_rend, int exit_code)
{
  if (app_rend != NULL) {
    SDL_DestroyRenderer(app_rend);
  }
  if (app_win != NULL) {
    SDL_DestroyWindow(app_win);
  }
  SDL_Quit();
  printf("Application closed with code %d\n", exit_code);
  exit(exit_code);
}

// Application INIT function

void app_init(const char win_caption[],
              SDL_Window **app_win,
              SDL_Renderer **app_rend)
{
  if ( SDL_Init(SDL_INIT_VIDEO) != 0 )
  {
     fprintf(stderr, "SDL initialization ERROR : %s\n", SDL_GetError());
     app_close(*app_win, *app_rend, 1);
  }
  *app_win = SDL_CreateWindow(win_caption,
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              main_win_width,
                              main_win_height,
                              SDL_WINDOW_SHOWN);
  if (*app_win == NULL)
  {
     fprintf(stderr, "SDL window creating ERROR : %s\n", SDL_GetError());
     app_close(*app_win, *app_rend, 1);
  }

  *app_rend = SDL_CreateRenderer(*app_win, -1, 0);
  if (*app_rend == NULL)
  {
     fprintf(stderr, "SDL renderer creating ERROR : %s\n", SDL_GetError());
     app_close(*app_win, *app_rend, 1);
  }
}
