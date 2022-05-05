#include <SDL2/SDL.h>
#include <math.h>

#include "wild_math.h"
#include "sdl_simple_draw.h"

const double angle_step = 0.5;


// angle - in radians

// angle_start and angle_end - in degrees

void sdl_draw_arc(SDL_Renderer* rend,
                  int center_x,
                  int center_y,
                  int rad,
                  double angle_start,
                  double angle_end)
{
  SDL_Point* arc_points;
  int arc_points_count;
  polar_coords current_point;
  int i;

  current_point.radius = rad;

  arc_points_count = ( (angle_end - angle_start) / angle_step) + 1;

  arc_points = (SDL_Point *) malloc(sizeof(SDL_Point) * arc_points_count);

  double current_angle;

  for(i = 0,
      current_angle = angle_start; i < arc_points_count;
      i++, current_angle += angle_step) {
    current_point.alpha = deg2rad(current_angle);
    rect_from_polar(center_x, center_y,
                    &current_point,
                    &arc_points[i].x, &arc_points[i].y);
  }
  SDL_RenderDrawLines(rend, arc_points, arc_points_count);
  free(arc_points);
}

void sdl_draw_circle_rel_line(SDL_Renderer* rend,
                              int center_x, int center_y,
                              double angle, int rad_start, int rad_end)
{
  polar_coords current_coords;
  int start_point_x, start_point_y, end_point_x, end_point_y;
  current_coords.alpha = angle;
  current_coords.radius = rad_start;
  rect_from_polar(center_x, center_y,
                  &current_coords,
                  &start_point_x, &start_point_y);
  current_coords.radius = rad_end;
  rect_from_polar(center_x, center_y,
                  &current_coords,
                  &end_point_x, &end_point_y);
  SDL_RenderDrawLine(rend,
                     start_point_x, start_point_y,
                     end_point_x, end_point_y);
}

static void sdl_draw_frame_base(SDL_Renderer* rend,
                                SDL_Point frame_start,
                                int frame_width, int frame_height,
                                int edge_size)
{
  SDL_RenderDrawLine(rend,
                     frame_start.x + edge_size,
                     frame_start.y,
                     frame_start.x + frame_width - edge_size,
                     frame_start.y);
  SDL_RenderDrawLine(rend,
                     frame_start.x + edge_size,
                     frame_start.y + frame_height,
                     frame_start.x + frame_width - edge_size,
                     frame_start.y + frame_height);
  SDL_RenderDrawLine(rend,
                     frame_start.x ,
                     frame_start.y + edge_size,
                     frame_start.x,
                     frame_start.y + frame_height - edge_size);
  SDL_RenderDrawLine(rend,
                     frame_start.x + frame_width,
                     frame_start.y + edge_size,
                     frame_start.x + frame_width,
                     frame_start.y + frame_height - edge_size);
}

void sdl_draw_chamfered_frame(SDL_Renderer* rend, SDL_Point frame_start,
                              int frame_width, int frame_height, int chamfer)
{
  sdl_draw_frame_base(rend, frame_start,
                      frame_width, frame_height, chamfer);
  SDL_RenderDrawLine(rend,
                     frame_start.x, frame_start.y + chamfer,
                     frame_start.x + chamfer, frame_start.y);
  SDL_RenderDrawLine(rend,
                     frame_start.x + frame_width - chamfer, frame_start.y,
                     frame_start.x + frame_width, frame_start.y + chamfer);
  SDL_RenderDrawLine(rend,
                     frame_start.x, frame_start.y + frame_height - chamfer,
                     frame_start.x + chamfer, frame_start.y + frame_height);
  SDL_RenderDrawLine(rend,
                     frame_start.x + frame_width,
                     frame_start.y + frame_height - chamfer,
                     frame_start.x + frame_width - chamfer,
                     frame_start.y + frame_height);
}

void sdl_draw_filleted_frame(SDL_Renderer* rend, SDL_Point frame_start,
                             int frame_width, int frame_height, int radius)
{
  SDL_Point arc_center;
  sdl_draw_frame_base(rend, frame_start,
                      frame_width, frame_height, radius);
  arc_center.x = frame_start.x + radius;
  arc_center.y = frame_start.y + radius;
  sdl_draw_arc(rend, arc_center.x, arc_center.y, radius, DEG_180, DEG_270);

  arc_center.x = frame_start.x + frame_width - radius;
  arc_center.y = frame_start.y + radius;
  sdl_draw_arc(rend, arc_center.x, arc_center.y, radius, DEG_270, DEG_360);

  arc_center.x = frame_start.x + radius;
  arc_center.y = frame_start.y + frame_height - radius;
  sdl_draw_arc(rend, arc_center.x, arc_center.y, radius, DEG_90, DEG_180);

  arc_center.x = frame_start.x + frame_width - radius;
  arc_center.y = frame_start.y + frame_height - radius;
  sdl_draw_arc(rend, arc_center.x, arc_center.y, radius, DEG_0, DEG_90);
}