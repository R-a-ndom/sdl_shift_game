/* * * * * * * * * * * * * * * * * * * *
 *  SDL_SHIFT_GAME                     *
 *        (and other projects)         *
 *                                     *
 *  SDL 2.0 demo - fifteen-like game   *
 *                                     *
 *  SDL_DIGIT_SEVEN.H -                *
 *        drawing numbers              *
 *        in seven-segment indicator   *
 *        style (SDL 2.0)              *
 *                                     *
 *          (c) Alexey Sorokin, 2022   *
 * * * * * * * * * * * * * * * * * * * *
 */

#ifndef SDL_DIGIT_SEVEN_H
#define SDL_DIGIT_SEVEN_H

#define MAX_DIGIT_SIGNS 15
#define MAX_SEGMENTS     7
#define MAX_DIGITS      10

#define FAT_SEGMENT_GAP   0.1
#define FAT_SEGMENT_WIDTH 0.1

enum { dir_horizontal, dir_vertical };

enum { seg_thin, seg_fat };

typedef struct {
  short int shift_horizontal;
  short int shift_vertical;
  short int direction;
} segment_info;

typedef short int digit_sequence[MAX_DIGITS];

void sdl_draw_seven_digit_number(SDL_Renderer* rend,
                                 const int segment_type,
                                 const int digit_length,
                                 const SDL_Point number_start,
                                 const unsigned int number);

#endif