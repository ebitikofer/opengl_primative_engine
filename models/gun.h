#ifndef GUN_M_H
#define GUN_M_H

#include <Angel.h>

#define PARTS_GUN     3

#define BARREL_W 3.0
#define BARREL_H 1.0
#define BARREL_D 0.75
#define BARREL_R 0.6
#define BARREL_G 0.6
#define BARREL_B 0.6

#define COLOR_BARREL  5
//   vec3(0.9, 0.6, 0.5),

#define SIGHT_W 2.0
#define SIGHT_H 0.25
#define SIGHT_D 0.25
#define SIGHT_R 0.5
#define SIGHT_G 0.5
#define SIGHT_B 0.5

#define HANDLE_W 0.6
#define HANDLE_H 2.0
#define HANDLE_D 0.5
#define HANDLE_R 0.4
#define HANDLE_G 0.4
#define HANDLE_B 0.4

// PICKUPS //

// GLfloat gun_mult = 1.0;

// vec3 gun_loc[NUM_GUNS] = {
//   vec3(50.0, 10.0, 50.0)
// };

vec3 gun_parts_diff[PARTS_GUN] = {
  vec3(0.0, 0.0 * 0.2, 0.0 * 0.2),
  vec3(0.0, -0.25 * 0.2, -0.75 * 0.2),
  vec3(0.0, -1.0 * 0.2, -0.025 * 0.2),
};

vec3 gun_parts_size[PARTS_GUN] = {
  vec3(BARREL_W*0.2, BARREL_H*0.2, BARREL_D*0.2),
  vec3(SIGHT_W*0.2, SIGHT_H*0.2, SIGHT_D*0.2),    //////////////////////////////
  vec3(HANDLE_W*0.2, HANDLE_H*0.2, HANDLE_D*0.2), //////////////////////////////
};

vec3 gun_parts_colors[PARTS_GUN] = {
  vec3(BARREL_R, BARREL_G, BARREL_B),
  vec3(SIGHT_R, SIGHT_G, SIGHT_B),
  vec3(HANDLE_R, HANDLE_G, HANDLE_B)
};

vec3 gun_parts_rot[PARTS_GUN] = { vec3(0.0, 0.0, 0.0) };

#endif
