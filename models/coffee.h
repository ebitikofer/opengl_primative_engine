#ifndef COFFEE_M_H
#define COFFEE_M_H

#include <Angel.h>

#define PARTS_COFFEE  6

#define COFFEE_W 1.0
#define COFFEE_H 1.0
#define COFFEE_D 1.0
#define CUP_W 1.25
#define CUP_H 1.25
#define CUP_D 1.25
#define SAUCER_W 2.0
#define SAUCER_H 0.1
#define SAUCER_D 2.0
#define COFFEE_R 0.1
#define COFFEE_G 0.1
#define COFFEE_B 0.0
#define DISH_R 0.9
#define DISH_G 0.9
#define DISH_B 1.0

// GLfloat coffee_mult = 1.0;

// vec3 coffee_loc[NUM_GUNS] = {
//   vec3(-50.0, 10.0, 50.0)
// };

vec3 coffee_parts_diff[PARTS_COFFEE] = {
  vec3(0.0, -0.8*0.2, 0.0*0.2),
  vec3(0.0, -0.8*0.2, 0.0*0.2),
  vec3(0.0, -1.0*0.2, 0.0*0.2),
  vec3(0.0, -1.0*0.2, 0.0*0.2),
  vec3(0.0, -1.5*0.2, 0.0*0.2),
  vec3(0.0, -1.5*0.2, 0.0*0.2)
};

vec3 coffee_parts_size[PARTS_COFFEE] = {
  vec3(COFFEE_W*0.2, COFFEE_H*0.2, COFFEE_D*0.2),
  vec3(COFFEE_W*0.2, COFFEE_H*0.2, COFFEE_D*0.2),
  vec3(CUP_W*0.2, CUP_H*0.2, CUP_D*0.2),
  vec3(CUP_W*0.2, CUP_H*0.2, CUP_D*0.2),
  vec3(SAUCER_W*0.2, SAUCER_H*0.2, SAUCER_D*0.2),
  vec3(SAUCER_W*0.2, SAUCER_H*0.2, SAUCER_D*0.2)
};

vec3 coffee_parts_colors[PARTS_COFFEE] = {
  vec3(COFFEE_R, COFFEE_G, COFFEE_B),
  vec3(COFFEE_R, COFFEE_G, COFFEE_B),
  vec3(DISH_R, DISH_G, DISH_B),
  vec3(DISH_R, DISH_G, DISH_B),
  vec3(DISH_R, DISH_G, DISH_B),
  vec3(DISH_R, DISH_G, DISH_B)
};

vec3 coffee_parts_rot[PARTS_COFFEE] = {
  vec3(0.0, -45.0, 0.0),
  vec3(0.0, 0, 0.0),
  vec3(0.0, -45.0, 0.0),
  vec3(0.0, 0, 0.0),
  vec3(0.0, -45.0, 0.0),
  vec3(0.0, 0, 0.0)
};

#endif
