#ifndef DRAWS_H
#define DRAWS_H


#ifdef DEBUG
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
  cell_width = 250,
  cell_height = 120,
  cell_chamfer = 5,
  cell_gap = 10,
};

#ifdef DEBUG

void debug_next_cross_state(cross_state* state);

void debug_draw_cross(SDL_Renderer* rend,
                             cross_state c_state);

#endif

void draw_statics(SDL_Renderer* rend);

void draw_all_field(SDL_Renderer* rend, const game_field field);


#endif