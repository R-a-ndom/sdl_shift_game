#ifndef SDL_SERV_H
#define SDL_SERV_H

extern const int main_win_height;
extern const int main_win_width;

#define HALF_SCREEN_WIDTH main_win_width / 2
#define HALF_SCREEN_HEIGHT main_win_height / 2

typedef struct {
  int c_red;
  int c_green;
  int c_blue;
} rgb_color_def;

#define SDL_CHANGE_COLOR(rend, color, alpha_channel) \
   SDL_SetRenderDrawColor( (rend), \
   (color.c_red), (color.c_green), (color.c_blue), \
   (alpha_channel) )

extern const rgb_color_def c16_black;

extern const rgb_color_def c16_red;
extern const rgb_color_def c16_green;
extern const rgb_color_def c16_yellow;
extern const rgb_color_def c16_magenta;
extern const rgb_color_def c16_cyan;

extern const rgb_color_def c16_gray;

extern const rgb_color_def c16_white;


int app_close(SDL_Window* app_win, SDL_Renderer* app_rend, int exit_code);

void app_init(const char win_caption[],
              SDL_Window **app_win,
              SDL_Renderer **app_rend);

#endif