#ifndef KEY_M_H
#define KEY_M_H

#include <Angel.h>

#define PARTS_KEY     6

#define KEYL_W 1.0
#define KEYL_H 1.0
#define KEYL_D 3.0
#define KEYS_W 1.0
#define KEYS_H 1.0
#define KEYS_D 2.0
#define KEY_R 0.9
#define KEY_G 0.7
#define KEY_B 0.0

// PICKUPS //

// GLfloat key_mult = 1.0;

// vec3 key_loc[NUM_GUNS] = {
//   vec3(50.0, 10.0, -50.0)
// };

vec3 key_parts_diff[PARTS_KEY] = {
  vec3(0, 0.0*0., 1.5*0.2),
  vec3(0, 0.0*0.2, -0.5*0.2),
  vec3(0, 0.0*0.2, -2.5*0.2),
  vec3(0, 1.5*0.2, -1.5*0.2),
  vec3(0, -1.5*0.2, -1.5*0.2),
  vec3(0, -1.0*0.2, 2.0*0.2)
};

vec3 key_parts_size[PARTS_KEY] = {
  vec3(KEYL_D*0.2, KEYL_H*0.2, KEYL_W*0.2), ////////////////////////////////////
  vec3(KEYL_H*0.2, KEYL_D*0.2, KEYL_W*0.2),
  vec3(KEYL_H*0.2, KEYL_D*0.2, KEYL_W*0.2),
  vec3(KEYS_D*0.2, KEYS_H*0.2, KEYS_W*0.2), ////////////////////////////////////
  vec3(KEYS_D*0.2, KEYS_H*0.2, KEYS_W*0.2), ////////////////////////////////////
  vec3(KEYS_H*0.2, KEYS_D*0.2, KEYS_W*0.2)
};

vec3 key_parts_colors[PARTS_KEY] = {
  vec3(KEY_R, KEY_G, KEY_B),
  vec3(KEY_R, KEY_G, KEY_B),
  vec3(KEY_R, KEY_G, KEY_B),
  vec3(KEY_R, KEY_G, KEY_B),
  vec3(KEY_R, KEY_G, KEY_B),
  vec3(KEY_R, KEY_G, KEY_B)
};

#endif
