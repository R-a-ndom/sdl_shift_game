#ifndef SHIFT_H
#define SHIFT_H

extern const game_field start_field;

void copy_field(game_field source, game_field dest);

void shift_run(SDL_Renderer* rend);

#endif