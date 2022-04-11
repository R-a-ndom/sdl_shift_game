#ifndef SDL_SIMPLE_DRAW_H
#define SDL_SIMPLE_DRAW_H

#define FPS_50 50

void sdl_draw_arc(SDL_Renderer* rend,
                  int center_x, int center_y, int radius,
                  double angle_start, double angle_end);

void sdl_draw_circle_rel_line(SDL_Renderer* rend,
                              int center_x, int center_y,
                              double angle, int rad_start, int rad_end);


void sdl_draw_chamfered_frame(SDL_Renderer* rend, SDL_Point frame_start,
                              int frame_width, int frame_height, int chamfer);

void sdl_draw_filleted_frame(SDL_Renderer* rend, SDL_Point frame_start,
                             int frame_width, int frame_height, int radius);


#define sdl_draw_circle(render, center_x, center_y, radius) \
        sdl_draw_arc( (render), (center_x), (center_y), (radius), 0.0, 360.0 )

#endif