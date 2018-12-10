#ifndef GHOST_M_H
#define GHOST_M_H

#include <Angel.h>

#define PARTS_GHOST   5

#define GHOST_W 2.0
#define GHOST_H 2.0
#define GHOST_D 2.0
#define GHOST_R 0.9
#define GHOST_G 0.9
#define GHOST_B 1.0

GLfloat ghost_height[PARTS_GHOST] = { 0.0 };

vec3 ghost_parts_colors[PARTS_GHOST] = {
  vec3(GHOST_R, GHOST_G, GHOST_B),
  vec3(GHOST_R, GHOST_G, GHOST_B),
  vec3(GHOST_R, GHOST_G, GHOST_B),
  vec3(GHOST_R, GHOST_G, GHOST_B),
  vec3(GHOST_R, GHOST_G, GHOST_B)
};

vec3 ghost_parts_rot[PARTS_GHOST] = {
  vec3(0.0, 0.0, 0.0),
  vec3(0.0, 0.0, 0.0),
  vec3(45.0, 0.0, 45.0),
  vec3(45.0, 0.0, 45.0),
  vec3(45.0, 0.0, 45.0)
};

#endif
