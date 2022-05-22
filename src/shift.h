/* * * * * * * * * * * * * * * * * * * *
 *  SDL_SHIFT_GAME                     *
 *                                     *
 *  SDL 2.0 demo - fifteen-like game   *
 *                                     *
 *  SHIFT.H - base game                *
 *            functions                *
 *                                     *
 *          (c) Alexey Sorokin, 2022   *
 * * * * * * * * * * * * * * * * * * * *
 */

#ifndef SHIFT_H
#define SHIFT_H

extern const game_field source_field;

extern const cell_pos empty_cell_begin_pos;

void shift_run(SDL_Renderer* rend);

#endif