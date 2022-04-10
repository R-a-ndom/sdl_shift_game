#ifndef DRAWS_H
#define DRAWS_H

enum {
  cell_width = 200,
  cell_height = 150,
  cell_chamfer = 30,
  cell_gap = 10,
};

void draw_statics(SDL_Renderer* rend);

#endif