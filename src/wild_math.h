/* * * * * * * * * * * * * * * * * * * *
 *  SDL_SHIFT_GAME                     *
 *        (and other projects)         *
 *                                     *
 *  SDL 2.0 demo - fifteen-like game   *
 *                                     *
 *  WILD_MATH.H -                      *
 *        math functions               *
 *        and types (SDL 2.0)          *
 *                                     *
 *          (c) Alexey Sorokin, 2022   *
 * * * * * * * * * * * * * * * * * * * *
 */

#ifndef WILD_MATH_H
#define WILD_MATH_H

/* polar coords,  alpha in radians */

typedef struct polar_coords {
  double radius;
  double alpha;
} polar_coords;

double rad2deg(double rad_alpha);

double deg2rad(double deg_alpha);


double circle_point_x(int center_x, polar_coords* polar_c);

double circle_point_y(int center_y, polar_coords* polar_c);

void rect_from_polar(int center_x, int center_y,
                     polar_coords* polar_c,
                     int* rect_x, int* rect_y);

#endif