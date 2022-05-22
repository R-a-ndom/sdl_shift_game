/* * * * * * * * * * * * * * * * * * * *
 *  SDL_SHIFT_GAME                     *
 *        (and other projects)         *
 *                                     *
 *  SDL 2.0 demo - fifteen-like game   *
 *                                     *
 *  SDL_SIMPLE_DRAW.H -                *
 *        drawing functions (SDL 2.0)  *
 *                                     *
 *          (c) Alexey Sorokin, 2022   *
 * * * * * * * * * * * * * * * * * * * *
 */

#ifndef SDL_SIMPLE_DRAW_H
#define SDL_SIMPLE_DRAW_H

#define FRAME_TIME 50

#define DEG_0     0.0
#define DEG_90   90.0
#define DEG_180 180.0
#define DEG_270 270.0
#define DEG_360 360.0

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
        sdl_draw_arc( (render), (center_x), (center_y), \
        (radius), DEG_0, DEG_360 )

#endif