#include "base.h"
#include "field.h"

const game_field source_field =
  { {  1,  2,  3,  4 },
    {  5,  6,  7,  8 },
    {  9, 10, 11, 12 },
    { 13, 14, 15,  0 } };

const cell_pos empty_cell_begin_pos = { 3, 3 };

void copy_field(const game_field source, game_field dest) {
  int i, j;
  for(i = 0; i < field_size; i++) {
    for(j = 0; j < field_size; j++) {
      dest[i][j] = source[i][j];
    }
  }
}

void fill_empty_pos(game_field field,
                    cell_pos* empty_cell_pos,
                    int shift_row, int shift_col) {
  cell_pos new_empty_pos;

  new_empty_pos.c_row = empty_cell_pos->c_row + shift_row;
  new_empty_pos.c_col = empty_cell_pos->c_col + shift_col;

  field[empty_cell_pos->c_row][empty_cell_pos->c_col] =
       field[new_empty_pos.c_row][new_empty_pos.c_col];

  field[new_empty_pos.c_row][new_empty_pos.c_col] = 0;

  *empty_cell_pos = new_empty_pos;
}
