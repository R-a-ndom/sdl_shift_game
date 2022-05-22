/* * * * * * * * * * * * * * * * * * * *
 *  SDL_SHIFT_GAME                     *
 *        (and other projects)         *
 *                                     *
 *  SDL 2.0 demo - fifteen-like game   *
 *                                     *
 *  WILD_MATH.C -                      *
 *        math functions               *
 *        and types (SDL 2.0)          *
 *                                     *
 *          (c) Alexey Sorokin, 2022   *
 * * * * * * * * * * * * * * * * * * * *
 */

#include <math.h>

#include "wild_math.h"

/* radians and degrees */

double deg2rad(double deg_alpha)
{
  return deg_alpha * M_PI / 180.0;
}

double rad2deg(double rad_alpha)
{
  return rad_alpha * 180.0 / M_PI;
}

/* from polar to decarts coordinates */

double circle_point_x(int center_x, polar_coords* polar_c)
{
  return (cos(polar_c->alpha) * polar_c->radius) + center_x;
}

double circle_point_y(int center_y, polar_coords* polar_c)
{
  return (sin(polar_c->alpha) * polar_c->radius) + center_y;
}

void rect_from_polar(int center_x, int center_y,
                     polar_coords* polar_c,
                     int* rect_x, int* rect_y)
{
  *rect_x = circle_point_x(center_x, polar_c);
  *rect_y = circle_point_y(center_y, polar_c);
}

/* --- *** --- */
