#ifndef SHIFT_H
#define SHIFT_H

enum {
  cell_empty, cell_not_empty,
};

enum {
  field_size = 4,
};

void shift_run(SDL_Renderer* rend);

#endif