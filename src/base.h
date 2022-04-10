#ifndef BASE_H
#define BASE_H

enum {
  cell_empty, cell_filled,
};

enum {
  field_size = 4,
};

typedef int game_field[field_size][field_size];

#endif