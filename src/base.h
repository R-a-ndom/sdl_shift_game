#ifndef BASE_H
#define BASE_H

enum {
  cell_empty, cell_filled,
};

enum {
  field_size = 4,
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
  int pos_x;
  int pos_y;
} cell_pos;

#endif