#include <SDL2/SDL.h>

#include "sdl_digit_seven.h"

/* how to draw every segment */

const segment_info all_segments_info[MAX_SEGMENTS] =
  { {0, 0, dir_horizontal }, {0, 0, dir_vertical   },
    {1, 0, dir_vertical   }, {0, 1, dir_horizontal },
    {0, 1, dir_vertical   }, {1, 1, dir_vertical   },
    {0, 2, dir_horizontal } };

/* how to draw every digit */
    
const short int all_digits_info[MAX_DIGITS][MAX_SEGMENTS] =
{ { 1, 1, 1, 0, 1, 1, 1 },   // 0
  { 0, 0, 1, 0, 0, 1, 0 },   // 1
  { 1, 0, 1, 1, 1, 0, 1 },   // 2
  { 1, 0, 1, 1, 0, 1, 1 },   // 3
  { 0, 1, 1, 1, 0, 1, 0 },   // 4
  { 1, 1, 0, 1, 0, 1, 1 },   // 5
  { 1, 1, 0, 1, 1, 1, 1 },   // 6
  { 1, 0, 1, 0, 0, 1, 0 },   // 7
  { 1, 1, 1, 1, 1, 1, 1 },   // 8
  { 1, 1, 1, 1, 0, 1, 1 } }; // 9

static int generate_digit_sequence(unsigned int src_num, digit_sequence seq)
{
  int i = 0;

  if ( src_num >= 10 ) {
    do {
      seq[i] = src_num % 10;
      i++;
      src_num /= 10;
    } while (src_num > 10); // DO-WHILE
  }
  seq[i] = src_num;
  i++;
  return i;
}

static void draw_one_segment(SDL_Renderer* rend, SDL_Point digit_draw_start, int digit_length, segment_info info)
{
  digit_draw_start.x +=info.shift_horizontal * digit_length;
  digit_draw_start.y +=info.shift_vertical * digit_length;
  if ( info.direction == dir_horizontal) {
    SDL_RenderDrawLine(rend, digit_draw_start.x, digit_draw_start.y,
                             digit_draw_start.x + digit_length, digit_draw_start.y); 
  } else {
    SDL_RenderDrawLine(rend, digit_draw_start.x, digit_draw_start.y,
                             digit_draw_start.x, digit_draw_start.y + digit_length); 
  
  }
}

static void draw_one_digit(SDL_Renderer* rend, SDL_Point digit_draw_start, int digit_length, int digit)
{
  int i;
  for(i = 0; i < MAX_SEGMENTS; i++) {
    if (all_digits_info[digit][i] == 1) {
      draw_one_segment(rend, digit_draw_start,
                       digit_length, all_segments_info[i]);
    }
  }
}

void sdl_draw_seven_digit_number(SDL_Renderer* rend,
                                 const SDL_Point number_start,
                                 const int digit_length,
                                 const unsigned int src_number)
{
  int i;
  int digit_gap;
  int digit_count;
  SDL_Point digit_draw_pos;
  digit_sequence seq;

  i = 0;
  digit_gap = digit_length / 5;
  digit_count = generate_digit_sequence(src_number, seq);
  digit_draw_pos.x = number_start.x + digit_count * digit_length + digit_gap * ( digit_count - 1 );
  digit_draw_pos.y = number_start.y;
  do {
    draw_one_digit(rend, digit_draw_pos, digit_length, seq[i]);
    digit_draw_pos.x -= digit_length;
    digit_draw_pos.x -= digit_gap;
    i++;
  } while (digit_draw_pos.x > number_start.x); // DO_WHILE
}
