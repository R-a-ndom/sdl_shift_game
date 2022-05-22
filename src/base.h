/* * * * * * * * * * * * * * * * * * * *
 *  SDL_SHIFT_GAME                     *
 *                                     *
 *  SDL 2.0 demo - fifteen-like game   *
 *                                     *
 *  BASE.H - game constants and types  *
 *                                     *
 *          (c) Alexey Sorokin, 2022   *
 * * * * * * * * * * * * * * * * * * * *
 */


#ifndef BASE_H
#define BASE_H

#define BOOL_TRUE 1
#define BOOL_FALSE 0


enum {
  cell_empty, cell_filled,
};

enum {
  field_size = 4,
  max_field_value = 15,
};

enum {
  state_continue = 100,

  state_move_up,
  state_move_down,
  state_move_left,
  state_move_right,

  state_quit,
};

typedef int game_field[field_size][field_size];

typedef struct {
  int c_row;
  int c_col;
} cell_pos;

#endif