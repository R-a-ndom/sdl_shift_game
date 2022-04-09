#ifndef SDL_SERV_H
#define SDL_SERV_H

extern const int main_win_height;
extern const int main_win_width;

#define HALF_SCREEN_WIDTH main_win_width / 2
#define HALF_SCREEN_HEIGHT main_win_height / 2


int app_close(SDL_Window* app_win, SDL_Renderer* app_rend, int exit_code);

void app_init(const char win_caption[],
              SDL_Window **app_win,
              SDL_Renderer **app_rend);

#endif