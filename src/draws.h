/* * * * * * * * * * * * * * * * * * * *
 *  SDL_SHIFT_GAME                     *
 *                                     *
 *  SDL 2.0 demo - fifteen-like game   *
 *                                     *
 *  DRAWS.H - game elements            *
 *            drawing unit             *
 *                                     *
 *          (c) Alexey Sorokin, 2022   *
 * * * * * * * * * * * * * * * * * * * *
 */


#ifndef DRAWS_H
#define DRAWS_H


#ifdef DEBUG  /* debug mode - little cross in middle */

enum {
  cross_shrink =  0,
  cross_grow   =  1,
  debug_cross_min    = 10,
  debug_cross_max    = 50,
};

typedef struct cross_state {
  int growing;
  int size;
} cross_state;

#endif

enum {
  big_frame_width = 1060,
  big_frame_height = 540,
  big_frame_chamfer = 25,
};

enum {
  cell_width = 250,
  cell_height = 120,
  cell_chamfer = 15,
  cell_gap = 10,
  cell_value_draw_gap = 15,
  cell_value_digit_length = 40,
};

#ifdef DEBUG

void debug_next_cross_state(cross_state* state);

void debug_draw_cross(SDL_Renderer* rend,
                             cross_state c_state);

#endif

void draw_statics(SDL_Renderer* rend);

void draw_all_field(SDL_Renderer* rend, const game_field field);


#endif