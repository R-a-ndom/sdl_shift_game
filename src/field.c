#ifdef DEBUG
#include <stdio.h>
#endif
#include <stdlib.h>
#include <time.h>

#include "base.h"
#include "field.h"

const game_field source_field =
  { {  1,  2,  3,  4 },
    {  5,  6,  7,  8 },
    {  9, 10, 11, 12 },
    { 13, 14, 15,  0 } };

const cell_pos empty_cell_begin_pos = { 3, 3 };

#ifdef DEBUG

static void debug_print_field_sequence(field_sequence seq) {
  int i;
  printf("sequence : [ ");
  for( i = 0; i < max_field_value; i++ ) {
    printf("%d ", seq[i]);
  }
  printf("]\n");
}

#endif

static void generate_field_sequence(field_sequence seq) {
  int i;
  for( i = 0; i < max_field_value; i++ ) {
    seq[i] = i + 1;
  }
}

static void mix_field_sequence(field_sequence seq) {
  int i,count;
  int tmp;
  int rnd_num;
  for(count = 0; count < MIX_COUNT; count++) {
    for(i = max_field_value - 1; i >= MIX_MIN; i--) {
      do {
        rnd_num = (int)((float)i*rand() / (RAND_MAX + 1.0 ));
      } while ( rnd_num == 0 );
#ifdef DEBUG
      printf("%d & %d | %d > ", count, rnd_num, i);
#endif
      tmp = seq[i];
      seq[i] = seq[rnd_num];
      seq[rnd_num] = tmp;
#ifdef DEBUG
      debug_print_field_sequence(seq);
#endif
    }
  }
}


static void fill_game_field(field_sequence src_seq, game_field dst_field) {
  int i, j;
  for(i = 0, j = 3; i < 4; i++, j--) {
    dst_field[0][i] = src_seq[j];
    dst_field[1][i] = src_seq[i + 4];
    dst_field[2][i] = src_seq[j + 8];
  }
  for(i = 0; i < 3; i++) {
    dst_field[3][i] = src_seq[i + 12];
  }
  dst_field[3][3] = cell_empty;
}

void generate_game_field(game_field field) {
  field_sequence seq;

  srand(time(NULL));
  generate_field_sequence(seq);
  mix_field_sequence(seq);
#ifdef DEBUG
  debug_print_field_sequence(seq);
#endif
  fill_game_field(seq, field);
}

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
