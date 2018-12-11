#ifndef LAUNCHER_M_H
#define LAUNCHER_M_H

#include <Angel.h>

#define PARTS_LAUNCHER     3

#define LAUNCHER_BARREL_W 6.0
#define LAUNCHER_BARREL_H 1.0
#define LAUNCHER_BARREL_D 1.0
#define LAUNCHER_BARREL_R 0.6
#define LAUNCHER_BARREL_G 0.6
#define LAUNCHER_BARREL_B 0.6

#define COLOR_LAUNCHER_BARREL  5
//   vec3(0.9, 0.6, 0.5),

#define LAUNCHER_SIGHT_W 2.0
#define LAUNCHER_SIGHT_H 0.25
#define LAUNCHER_SIGHT_D 0.25
#define LAUNCHER_SIGHT_R 0.5
#define LAUNCHER_SIGHT_G 0.5
#define LAUNCHER_SIGHT_B 0.5

#define LAUNCHER_HANDLE_W 0.6
#define LAUNCHER_HANDLE_H 2.0
#define LAUNCHER_HANDLE_D 0.5
#define LAUNCHER_HANDLE_R 0.4
#define LAUNCHER_HANDLE_G 0.4
#define LAUNCHER_HANDLE_B 0.4

// PICKUPS //

// GLfloat launcher_mult = 1.0;

// vec3 launcher_loc[NUM_LAUNCHERS] = {
//   vec3(50.0, 10.0, 50.0)
// };

vec3 launcher_parts_diff[PARTS_LAUNCHER] = {
  vec3(0.0, 0.0 * 0.2, 0.0 * 0.2),
  vec3(90.0, -0.25 * 0.2, -0.75 * 0.2),
  vec3(0.0, -1.0 * 0.2, -0.025 * 0.2),
};
vec3 launcher_parts_size[PARTS_LAUNCHER] = {
  vec3(LAUNCHER_BARREL_W*0.2, LAUNCHER_BARREL_H*0.2, LAUNCHER_BARREL_D*0.2),
  vec3(LAUNCHER_SIGHT_W*0.2, LAUNCHER_SIGHT_H*0.2, LAUNCHER_SIGHT_D*0.2),    //////////////////////////////
  vec3(LAUNCHER_HANDLE_W*0.2, LAUNCHER_HANDLE_H*0.2, LAUNCHER_HANDLE_D*0.2), //////////////////////////////
};

vec3 launcher_parts_colors[PARTS_LAUNCHER] = {
  vec3(LAUNCHER_BARREL_R, LAUNCHER_BARREL_G, LAUNCHER_BARREL_B),
  vec3(LAUNCHER_SIGHT_R, LAUNCHER_SIGHT_G, LAUNCHER_SIGHT_B),
  vec3(LAUNCHER_HANDLE_R, LAUNCHER_HANDLE_G, LAUNCHER_HANDLE_B)
};

vec3 launcher_parts_rot[PARTS_LAUNCHER] = { vec3(0.0, 0.0, 0.0) };

#endif
