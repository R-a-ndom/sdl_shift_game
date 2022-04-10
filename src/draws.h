#ifndef DRAWS_H
#define DRAWS_H

enum {
#ifdef DEBUG
  debug_cross_size = 50,
#endif
  cell_width = 250,
  cell_height = 120,
  cell_chamfer = 5,
  cell_gap = 10,
};

void draw_statics(SDL_Renderer* rend);

#endif