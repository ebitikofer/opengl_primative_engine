#ifndef LASER_M_H
#define LASER_M_H

#include <Angel.h>

#define PARTS_LASER     3

#define LASER_BARREL_W 3.0
#define LASER_BARREL_H 1.0
#define LASER_BARREL_D 0.5
#define LASER_BARREL_R 0.6
#define LASER_BARREL_G 0.6
#define LASER_BARREL_B 0.6

#define COLOR_LASER_BARREL  5
//   vec3(0.9, 0.6, 0.5),

#define LASER_SIGHT_W 2.0
#define LASER_SIGHT_H 0.25
#define LASER_SIGHT_D 0.25
#define LASER_SIGHT_R 0.5
#define LASER_SIGHT_G 0.5
#define LASER_SIGHT_B 0.5

#define LASER_HANDLE_W 0.6
#define LASER_HANDLE_H 1.5
#define LASER_HANDLE_D 0.5
#define LASER_HANDLE_R 0.4
#define LASER_HANDLE_G 0.4
#define LASER_HANDLE_B 0.4

// PICKUPS //

// GLfloat laser_mult = 1.0;

// vec3 laser_loc[NUM_LASERS] = {
//   vec3(50.0, 10.0, 50.0)
// };

vec3 laser_parts_diff[PARTS_LASER] = {
  vec3(0.0, 0.0 * 0.2, 0.0 * 0.2),
  vec3(0.0, 0.5 * 0.2, -1.0 * 0.2),
  vec3(0.0, -0.75 * 0.2, -0.75 * 0.2),
};

vec3 laser_parts_size[PARTS_LASER] = {
  vec3(LASER_BARREL_W*0.2, LASER_BARREL_H*0.2, LASER_BARREL_D*0.2),
  vec3(LASER_SIGHT_W*0.2, LASER_SIGHT_H*0.2, LASER_SIGHT_D*0.2),    //////////////////////////////
  vec3(LASER_HANDLE_W*0.2, LASER_HANDLE_H*0.2, LASER_HANDLE_D*0.2), //////////////////////////////
};

vec3 laser_parts_colors[PARTS_LASER] = {
  vec3(LASER_BARREL_R, LASER_BARREL_G, LASER_BARREL_B),
  vec3(LASER_SIGHT_R, LASER_SIGHT_G, LASER_SIGHT_B),
  vec3(LASER_HANDLE_R, LASER_HANDLE_G, LASER_HANDLE_B)
};

vec3 laser_parts_rot[PARTS_LASER] = { vec3(0.0, 0.0, 0.0) };

#endif
